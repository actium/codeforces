#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

unsigned count(const graph_t& g, size_t u, unsigned d, std::vector<unsigned>& c)
{
    if (c[u] == 0) {
        c[u] = d;

        unsigned k = 0;
        for (const size_t x : g[u])
            k += count(g, x, d + 1, c);

        return k;
    }
    return c[u] < d ? (d - c[u]) % 2 : 0;
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
        std::vector<unsigned> c(n);
        for (size_t i = 0; i < n; ++i) {
            if (c[i] == 0)
                k += count(g, i, 1, c);
        }
    }

    answer(k + (n - k) % 2);
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
