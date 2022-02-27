#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

double traverse(const graph_t& g, size_t v, size_t p)
{
    double d = 0;
    for (const size_t u : g[v]) {
        if (u != p)
            d += 1 + traverse(g, u, v);
    }

    if (d == 0)
        return 0;

    return d / (g[v].size() - (v != 0));
}

void answer(double x)
{
    std::cout << std::fixed << x << '\n';
}

void solve(const graph_t& g)
{
    answer(traverse(g, 0, 0));
}

int main()
{
    size_t n;
    std::cin >> n;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    solve(g);

    return 0;
}
