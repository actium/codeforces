#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;
using integer = unsigned long long;

std::pair<unsigned, bool> count(const graph_t& g, size_t u, size_t p, size_t x)
{
    std::pair<unsigned, bool> s = { 1, u == x };
    for (const size_t v : g[u]) {
        if (v == p)
            continue;

        const std::pair<unsigned, bool> r = count(g, v, u, x);
        if (r.second)
            return r;

        s.first += r.first;
    }
    return s;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const graph_t& g, size_t s, size_t t)
{
    const integer n = g.size(), u = count(g, s, s, t).first, v = count(g, t, t, s).first;
    answer(n * (n - 1) - u * v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned x, y;
    std::cin >> x >> y;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    solve(g, x-1, y-1);

    return 0;
}
