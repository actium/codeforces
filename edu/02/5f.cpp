#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

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

        c_.resize(n);
        for (size_t i = 1; i < n; ++i)
            c_[p_[i]] = c_[p_[i-1]] + (s_[p_[i]] != s_[p_[i-1]]);

        std::vector<unsigned> q(n);
        for (unsigned k = 1; k < n && c_[p_.back()] + 1 != n; k *= 2) {
            for (size_t i = 0; i < n; ++i)
                p_[i] = (p_[i] - k + n) % n;

            std::swap(c_, q);
            sort(p_, q);

            size_t x = p_[0];
            c_[x] = 0;
            for (const size_t y : p_) {
                c_[y] = c_[x] + (q[y] != q[x] || q[(y + k) % n] != q[(x + k) % n]);
                x = y;
            }
        }

        std::vector<unsigned> lcp(n);
        for (size_t i = 0, k = 0; i + 1 < n; ++i, k -= (k > 0)) {
            const unsigned x = c_[i] - 1;
            for (size_t j = p_[x]; s_[i+k] == s_[j+k]; ++k);
            lcp[x] = k;
        }

        lcp_.push_back(std::move(lcp));
        for (size_t d = 1, j = 2; j < n; ++d, j *= 2) {
            lcp.resize(n);
            for (size_t i = 0; i + j <= n; ++i)
                lcp[i] = std::min(lcp_[d-1][i], lcp_[d-1][i + j / 2]);

            lcp_.push_back(std::move(lcp));
        }
    }

    unsigned rank(size_t x) const
    {
        return c_[x];
    }

    unsigned lcp(size_t d, size_t i) const
    {
        return lcp_[d][i];
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
    std::vector<unsigned> c_;
    std::vector<std::vector<unsigned>> lcp_;

}; // class SuffixArray

unsigned solve(std::string s)
{
    const size_t n = s.length();

    std::string t(s.rbegin(), s.rend());

    s.push_back(' ');
    SuffixArray sa(s);

    t.push_back(' ');
    SuffixArray ta(t);

    unsigned k = 1;
    for (size_t q = 1; q < n; ++q) {
        for (size_t x = 0; q * (x + 1) < n; ++x) {
            const auto sr = std::minmax({ sa.rank(q * x), sa.rank(q * (x + 1)) });
            const unsigned sd = __builtin_clz(1) - __builtin_clz(sr.second - sr.first);
            const unsigned re = std::min(sa.lcp(sd, sr.first), sa.lcp(sd, sr.second - (1 << sd)));

            const auto tr = std::minmax({ ta.rank(n - 1 - q * x), ta.rank(n - 1 - q * (x + 1)) });
            const unsigned td = __builtin_clz(1) - __builtin_clz(tr.second - tr.first);
            const unsigned le = std::min(ta.lcp(td, tr.first), ta.lcp(td, tr.second - (1 << td)));

            k = std::max<unsigned>(k, (le + q + re - 1) / q);
        }
    }
    return k;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    std::cout << solve(std::move(s)) << '\n';

    return 0;
}
