#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void traverse(const graph_t& g, size_t u, size_t p, std::vector<unsigned>& d, std::vector<std::vector<size_t>>& j)
{
    d[u] = d[p] + (p != u);

    j[u][0] = p;
    for (size_t i = 1; i < j[u].size(); ++i)
        j[u][i] = j[j[u][i-1]][i-1];

    for (const size_t x : g[u]) {
        if (x != p)
            traverse(g, x, u, d, j);
    }
}

void solve(const graph_t& g, size_t x)
{
    const size_t n = g.size(), m = 32 - __builtin_clz(n + 1);

    std::vector<unsigned> d(n);
    std::vector<std::vector<size_t>> j(n, std::vector<size_t>(m));
    traverse(g, 0, 0, d, j);

    const auto lca = [&](size_t u, size_t v) {
        if (d[v] < d[u])
            std::swap(u, v);

        for (size_t i = m-1; ~i != 0; --i) {
            if (d[j[v][i]] >= d[u])
                v = j[v][i];
        }

        if (v == u)
            return v;

        for (size_t i = m-1; ~i != 0; --i) {
            if (j[v][i] != j[u][i]) {
                v = j[v][i];
                u = j[u][i];
            }
        }
        return j[v][0];
    };

    unsigned k = 0;
    for (size_t i = 1; i < n; ++i) {
        if (d[x] < 2 * d[lca(x, i)])
            k = std::max(k, d[i]);
    }

    answer(2 * k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned x;
    std::cin >> x;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    solve(g, x-1);

    return 0;
}
