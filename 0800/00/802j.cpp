#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<std::pair<size_t, unsigned>>>;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned search(const graph_t& g, size_t u, std::vector<bool>& v)
{
    unsigned c = 0;

    v[u] = true;
    for (const std::pair<size_t, unsigned>& e : g[u]) {
        if (!v[e.first])
            c = std::max(c, e.second + search(g, e.first, v));
    }

    return c;
}

void solve(const graph_t& g)
{
    const size_t n = g.size();

    std::vector<bool> v(n);
    answer(search(g, 0, v));
}

int main()
{
    size_t n;
    std::cin >> n;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        size_t u, v, c;
        std::cin >> u >> v >> c;
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }

    solve(g);

    return 0;
}
