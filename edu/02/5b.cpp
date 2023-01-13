#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class SuffixArray {
public:
    explicit SuffixArray(const std::string& s)
        : s_(s)
    {
        const size_t n = s_.length();

        p_.resize(n);
        for (size_t i = 0; i < n; ++i)
            p_[i] = i;

        std::sort(p_.begin(), p_.end(), [this](size_t x, size_t y) { return s_[x] < s_[y]; });

        std::vector<unsigned> c(n);
        for (size_t i = 1; i < n; ++i)
            c[p_[i]] = c[p_[i-1]] + (s_[p_[i]] != s_[p_[i-1]]);

        for (unsigned k = 1; k < n; k *= 2) {
            for (size_t i = 0; i < n; ++i)
                p_[i] = (p_[i] - k + n) % n;

            sort(p_, c);

            std::vector<unsigned> q(n);
            {
                size_t x = p_[0];
                for (const size_t y : p_) {
                    q[y] = q[x] + (c[y] != c[x] || c[(y + k) % n] != c[(x + k) % n]);
                    x = y;
                }
            }
            c = std::move(q);
        }

        lcp_.resize(n);
        for (size_t i = 0, k = 0; i < n - 1; ++i) {
            if (k > 0)
                --k;

            const size_t j = p_[c[i] - 1];
            while (s_[i+k] == s_[j+k])
                ++k;

            lcp_[c[i]] = k;
        }
    }

    std::pair<size_t, size_t> search(size_t m) const
    {
        const size_t n = p_.size();

        std::pair<size_t, size_t> p = { 0, 0 };
        for (size_t i = 1; i < n; ++i) {
            const size_t x = p_[i-1], y = p_[i];
            if ((x < m) == (y < m))
                continue;

            if (lcp_[i] > p.second) {
                p.first = x;
                p.second = lcp_[i];
            }
        }
        return p;
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

    std::string s, t;
    std::cin >> s >> t;

    const size_t m = s.length();

    s.push_back('#');
    s += t;
    s.push_back(' ');

    SuffixArray sa(s);

    const auto p = sa.search(m);
    std::cout << s.substr(p.first, p.second) << '\n';

    return 0;
}
