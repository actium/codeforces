#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

unsigned explore(const graph_t& g, size_t u, size_t p, std::vector<bool>& v)
{
    v[u] = true;

    unsigned c = 1;
    for (const size_t x : g[u]) {
        if (x == p)
            continue;

        if (v[x] || explore(g, x, u, v) == 0)
            c = 0;
    }

    return c;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const graph_t& g)
{
    const size_t n = g.size();

    unsigned k = 0;
    {
        std::vector<bool> v(n);
        for (size_t i = 0; i < n; ++i) {
            if (!v[i])
                k += explore(g, i, i, v);
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
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    solve(g);

    return 0;
}
