#include <algorithm>
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

    std::vector<size_t> o(n);
    for (size_t i = 0; i < n; ++i)
        o[i] = i;

    std::sort(o.begin(), o.end(), [&](size_t x, size_t y) {
        return g[x].size() > g[y].size();
    });

    std::vector<unsigned> t(n);
    {
        std::vector<bool> m(n), v(n);
        for (const size_t x : o) {
            for (const size_t u : g[x])
                m[u] = !v[u];

            for (const size_t u : g[x]) {
                if (!m[u])
                    continue;

                for (const size_t w : g[u]) {
                    if (m[w]) {
                        ++t[x];
                        ++t[u];
                        ++t[w];
                    }
                }

                m[u] = false;
            }

            v[x] = true;
        }
    }

    integer q = 0;
    for (size_t i = 0; i < n; ++i)
        q += g[i].size() * (g[i].size() - 1ull) / 2 - t[i];

    answer(q);
}

void test_case()
{
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
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
