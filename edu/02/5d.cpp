#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using integer = unsigned long long;

class SuffixArray {
public:
    explicit SuffixArray(const std::string& s)
        : s_(s)
    {
        const size_t n = s_.size();

        p_.resize(n);
        for (size_t i = 0; i < n; ++i)
            p_[i] = i;

        std::sort(p_.begin(), p_.end(), [this](size_t x, size_t y) { return s_[x] < s_[y]; });

        std::vector<unsigned> c(n);
        for (size_t i = 1; i < n; ++i)
            c[p_[i]] = c[p_[i-1]] + (s_[p_[i]] != s_[p_[i-1]]);

        std::vector<unsigned> q(n);
        for (unsigned k = 1; k < n && c[p_.back()] + 1 != n; k *= 2) {
            for (size_t i = 0; i < n; ++i)
                p_[i] = (p_[i] - k + n) % n;

            std::swap(c, q);
            sort(p_, q);

            size_t x = p_[0];
            c[x] = 0;
            for (const size_t y : p_) {
                c[y] = c[x] + (q[y] != q[x] || q[(y + k) % n] != q[(x + k) % n]);
                x = y;
            }
        }

        lcp_.resize(n);
        for (size_t i = 0, k = 0; i < n - 1; ++i, k -= (k > 0)) {
            const size_t j = p_[c[i] - 1];
            while (s_[i+k] == s_[j+k])
                ++k;

            lcp_[c[i] - 1] = k;
        }
    }

    integer count_borders() const
    {
        const size_t n = p_.size();

        integer k = n * (n - 1ull) / 2;

        std::vector<std::pair<size_t, unsigned>> t;
        for (size_t i = 0; i < n; ++i) {
            size_t j = i;
            while (!t.empty() && t.back().second >= lcp_[i]) {
                const auto x = t.back();
                t.pop_back();

                if (x.second > lcp_[i]) {
                    const unsigned y = t.empty() ? lcp_[i] : std::max(lcp_[i], t.back().second);

                    const integer d = i - x.first + 1;
                    k += d * (d - 1) / 2 * (x.second - y);
                }

                j = x.first;
            }
            t.emplace_back(j, lcp_[i]);
        }

        return k;
    }

private:
    static void sort(std::vector<size_t>& p, const std::vector<unsigned>& c)
    {
        const size_t n = p.size();

        std::vector<unsigned> x(1 + n);
        for (size_t i = 0; i < n; ++i)
            ++x[1 + c[i]];

        for (size_t i = 1; i < n; ++i)
            x[i] += x[i-1];

        std::vector<size_t> q(n);
        {
            for (const size_t i : p)
                q[x[c[i]]++] = i;
        }
        p = std::move(q);
    }

private:
    const std::string& s_;

    std::vector<size_t> p_;
    std::vector<unsigned> lcp_;

}; // class SuffixArray

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    s.push_back(' ');
    SuffixArray sa(s);

    std::cout << sa.count_borders() << '\n';

    return 0;
}
