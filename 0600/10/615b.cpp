#include <iostream>
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

    std::vector<unsigned> s(n, 1);
    for (size_t i = 0; i < n; ++i) {
        for (const size_t u : g[i]) {
            if (u < i)
                s[i] = std::max(s[i], s[u] + 1);
        }
    }

    integer v = 0;
    for (size_t i = 0; i < n; ++i)
        v = std::max<integer>(v, 1ull * s[i] * g[i].size());

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    graph_t g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    solve(g);

    return 0;
}
