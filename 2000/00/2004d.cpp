#include <algorithm>
#include <iostream>
#include <vector>

constexpr unsigned oo = ~0u;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

unsigned index(char c1, char c2)
{
    if (c1 == 'B')
        return c2 == 'G' ? 0 : c2 == 'R' ? 1 : 2;

    if (c1 == 'G')
        return c2 == 'B' ? 3 : c2 == 'R' ? 4 : 5;

    if (c1 == 'R')
        return c2 == 'B' ? 6 : c2 == 'G' ? 7 : 8;

    return c2 == 'B' ? 9 : c2 == 'G' ? 10 : 11;
}

unsigned distance(unsigned s, unsigned t)
{
    return std::max(s, t) - std::min(s, t);
}

void solve(const std::vector<std::string>& c, const std::vector<std::pair<unsigned, unsigned>>& r)
{
    const size_t n = c.size();

    std::vector<size_t> p[12];
    for (size_t i = 0; i < n; ++i) {
        p[index(c[i][0], c[i][1])].push_back(i);
        p[index(c[i][1], c[i][0])].push_back(i);
    }

    const auto search = [&](char u, char v, size_t x) {
        std::vector<unsigned> r;
        if (u != v) {
            const std::vector<size_t>& s = p[index(u, v)];

            const auto it = std::lower_bound(s.begin(), s.end(), x);
            if (it != s.end())
                r.push_back(1 + *it);

            if (it != s.begin())
                r.push_back(1 + *std::prev(it));
        }
        return r;
    };

    for (auto [s, t] : r) {
        if (s > t)
            std::swap(s, t);

        unsigned d = oo;
        for (size_t i = 0; i < 2; ++i) {
            for (size_t j = 0; j < 2; ++j) {
                for (const size_t x : search(c[s-1][i], c[t-1][j], s-1))
                    d = std::min(d, distance(s, x) + distance(x, t));
            }
        }

        d != oo ? answer(d) : no_answer();
   }
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::vector<std::string> c(n);
    std::cin >> c;

    std::vector<std::pair<unsigned, unsigned>> r(q);
    std::cin >> r;

    solve(c, r);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
