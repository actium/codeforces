#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& g, size_t a, size_t b)
{
    const size_t n = g.size(), m = g[0].size();

    const auto c = [&g](size_t r, size_t c, size_t a, size_t b) {
        unsigned k = 0;
        for (size_t i = 0; i < a; ++i) {
            for (size_t j = 0; j < b; ++j)
                k += g[r+i][c+j];
        }
        return k;
    };

    unsigned v = ~0u;
    for (size_t i = 0; i + a <= n; ++i) {
        for (size_t j = 0; j + b <= m; ++j)
            v = std::min(v, c(i, j, a, b));
    }
    for (size_t i = 0; i + b <= n; ++i) {
        for (size_t j = 0; j + a <= m; ++j)
            v = std::min(v, c(i, j, b, a));
    }

    answer(v);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> g(n, std::vector<unsigned>(m));
    std::cin >> g;

    size_t a, b;
    std::cin >> a >> b;

    solve(g, a, b);

    return 0;
}

