#include <iostream>
#include <map>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const graph_t& g)
{
    const size_t n = g.size();

    integer k = 0;
    for (size_t i = 0; i < n; ++i) {
        std::map<unsigned, unsigned> f;
        for (const size_t u : g[i]) {
            for (const size_t v : g[u])
                ++f[v];
        }

        for (const auto& e : f) {
            if (e.first != i)
                k += e.second * (e.second - 1ull) / 2;
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    graph_t g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned a, b;
        std::cin >> a >> b;

        g[a-1].push_back(b-1);
    }

    solve(g);

    return 0;
}
