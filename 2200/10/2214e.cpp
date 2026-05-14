#include <iostream>
#include <vector>

constexpr unsigned oo = ~0u >> 1;

void answer(const std::vector<int>& v)
{
    for (const int x : v)
        std::cout << x << '\n';
}

void solve(std::vector<std::vector<unsigned>>& d)
{
    const size_t n = d.size();

    for (size_t i = 0; i < n; ++i)
        d[i][i] = 0;

    for (size_t i = 0; i < n; ++i) {
        for (size_t k = 0; k < n; ++k) {
            for (size_t j = 0; j < n; ++j)
                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
        }
    }

    std::vector<int> r(n-1, -1);
    for (size_t i = 1; i < n; ++i) {
        if (d[0][i] != oo)
            r[i-1] = d[0][i];
    }

    answer(r);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<unsigned>> d(n, std::vector<unsigned>(n, oo));
    for (size_t i = 0; i < m; ++i) {
        unsigned u, v, w;
        std::cin >> u >> v >> w;

        d[u-1][v-1] = w;
        d[v-1][u-1] = w;
    }

    solve(d);

    return 0;
}
