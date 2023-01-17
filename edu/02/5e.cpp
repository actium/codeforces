#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Answer {
    const std::vector<unsigned>& s;

    size_t i;
    size_t k;
    integer r;

    explicit Answer(const std::vector<unsigned>& s)
        : s(s), i(0), k(s.size() - 1), r(k)
    {}
};

std::ostream& operator <<(std::ostream& output, const Answer& a)
{
    output << a.r << '\n';
    output << a.k << '\n';

    const char* separator = "";
    for (size_t i = 0; i < a.k; ++i) {
        output << separator << a.s[a.i + i];
        separator = " ";
    }

    return output;
}

class SuffixArray {
public:
    explicit SuffixArray(const std::vector<unsigned>& s)
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
        for (size_t i = 0, k = 0; i < n - 1; ++i, k -= (k > 0)) {
            const size_t j = p_[c[i] - 1];
            while (s_[i+k] == s_[j+k])
                ++k;

            lcp_[c[i] - 1] = k;
        }
    }

    Answer search() const
    {
        const size_t n = p_.size();

        Answer a(s_);

        std::vector<size_t> t;
        for (size_t i = 0; i < n; ++i) {
            while (!t.empty() && lcp_[t.back()] > lcp_[i]) {
                const size_t x = t.back();
                t.pop_back();

                const integer h = lcp_[x], w = (t.empty() ? i + 1 : i - t.back());
                if (h * w > a.r) {
                    a.i = p_[i + 1 - w];
                    a.k = h;
                    a.r = h * w;
                }
            }

            t.push_back(i);
        }

        return a;
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
    const std::vector<unsigned>& s_;

    std::vector<size_t> p_;
    std::vector<unsigned> lcp_;

}; // class SuffixArray

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> s(n);
    std::cin >> s;

    s.push_back(0);
    SuffixArray sa(s);
    std::cout << sa.search() << '\n';

    return 0;
}
