#include <iostream>
#include <string>
#include <vector>

constexpr unsigned oo = ~0u >> 1;

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

void solve(const std::vector<std::string>& g)
{
    const size_t n = g.size(), m = g[0].size();

    std::vector<unsigned> d(m);
    for (size_t i = 0; i < n; ++i) {
        const size_t x = g[i].find('1');
        if (x == std::string::npos)
            return no_answer();

        for (size_t j = 0, p = x, q = g[i].rfind('1'); j < m; ++j) {
            if (j > p) {
                q = m + p;
                p = g[i].find('1', j);
                if (p == std::string::npos)
                    p = m + x;
            }

            d[j] += std::min(p - j, m - q + j);
        }
    }

    unsigned x = oo;
    for (size_t i = 0; i < m; ++i)
        x = std::min(x, d[i]);

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::string> g(n);
    std::cin >> g;

    solve(g);

    return 0;
}