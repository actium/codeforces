#include <algorithm>
#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned distance(const graph_t& g, size_t u, size_t p, size_t t)
{
    if (u == t)
        return 0;

    for (const size_t v : g[u]) {
        if (v == p)
            continue;

        const unsigned d = distance(g, v, u, t);
        if (d != ~0u)
            return 1 + d;
    }
    return ~0u;
}

unsigned prepare(const graph_t& g, size_t u, size_t p, std::vector<unsigned>& h)
{
    for (const size_t v : g[u]) {
        if (v != p)
            h[u] = std::max(h[u], 1 + prepare(g, v, u, h));
    }
    return h[u];
}

bool paint(graph_t& g, size_t u, size_t p, unsigned& d, unsigned& k, const std::vector<unsigned>& h)
{
    if (k == g.size())
        return true;

    std::sort(g[u].begin(), g[u].end(), [&](size_t x, size_t y) {
        return h[x] < h[y];
    });

    for (const size_t v : g[u]) {
        if (v != p && paint(g, v, u, ++d, ++k, h))
            return true;
    }
    ++d;

    return false;
}

void solve(graph_t& g, size_t s, size_t t)
{
    const size_t n = g.size();

    const auto check = [&](size_t x) {
        std::vector<unsigned> h(n);
        prepare(g, x, x, h);

        unsigned d = 0, k = 1;
        paint(g, x, x, d, k, h);
        return d;
    };

    const unsigned u = check(s), v = check(t), d = distance(g, s, s, t);
    answer(d + std::min(u, v + d % 2));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned a, b;
    std::cin >> a >> b;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    solve(g, a-1, b-1);
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
