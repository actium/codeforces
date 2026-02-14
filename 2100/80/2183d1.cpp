#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void explore(const graph_t& g, size_t u, size_t p, unsigned d, std::vector<unsigned>& h)
{
    ++h[d];

    for (const size_t v : g[u]) {
        if (v != p)
            explore(g, v, u, d+1, h);
    }
}

void solve(const graph_t& g)
{
    const size_t n = g.size();

    std::vector<unsigned> h(n);
    explore(g, 0, 0, 0, h);

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        k = std::max(k, h[i]);
        k = std::max<unsigned>(k, g[i].size());
    }

    answer(k);
}

void test_case()
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

    g[0].push_back(0);      // sentinel
    solve(g);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
