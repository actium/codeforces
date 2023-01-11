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
    }

    size_t lower_bound(const std::string& t) const
    {
        const size_t n = s_.length(), m = t.length();

        const auto check = [&](size_t i, size_t j) {
            for ( ; i < n && j < m; ++i, ++j) {
                if (s_[i] != t[j])
                    return s_[i] < t[j];
            }
            return i == n && j < m;
        };

        size_t lb = 0, ub = n;
        while (lb + 1 < ub) {
            const size_t mid = (lb + ub) / 2;
            (check(p_[mid], 0) ? lb : ub) = mid;
        }

        return ub < n ? p_[ub] : n;
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

}; // class SuffixArray

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string t;
    std::cin >> t;

    t.push_back(' ');
    SuffixArray sa(t);

    size_t n;
    std::cin >> n;

    for (size_t i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;

        const size_t x = sa.lower_bound(s);
        answer(t.substr(x, s.length()) == s);
    }

    return 0;
}
