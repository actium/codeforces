#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(const std::vector<std::vector<unsigned>>& g)
{
    const size_t n = g.size(), m = g[0].size();

    unsigned long long k = 0;
    for (size_t i = 0; i < n; ++i) {
        unsigned f[2] = {};
        for (size_t j = 0; j < m; ++j)
            ++f[g[i][j]];

        k += (1ull << f[0]) - 1;
        k += (1ull << f[1]) - 1;
    }
    for (size_t j = 0; j < m; ++j) {
        unsigned f[2] = {};
        for (size_t i = 0; i < n; ++i)
            ++f[g[i][j]];

        k += (1ull << f[0]) - 1;
        k += (1ull << f[1]) - 1;
    }

    answer(k - n * m);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> g(n, std::vector<unsigned>(m));
    std::cin >> g;

    solve(g);

    return 0;
}

