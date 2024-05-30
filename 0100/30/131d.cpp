#include <algorithm>
#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

size_t find_cycle(const graph_t& g, size_t u, size_t p, std::vector<unsigned>& v, std::vector<size_t>& c)
{
    const size_t n = g.size();

    if (v[u] == 0) {
        v[u] = 1;
        for (const size_t x : g[u]) {
            if (x == p)
                continue;

            const size_t t = find_cycle(g, x, u, v, c);
            if (t < n) {
                c.push_back(u);
                return u == t ? n : t;
            }
        }
        v[u] = 2;
    }
    return v[u] == 2 ? n : u;
}

void compute_distances(const graph_t& g, size_t u, std::vector<bool>& v, std::vector<unsigned>& d)
{
    v[u] = true;

    for (const size_t x : g[u]) {
        if (!v[x]) {
            d[x] = std::min(d[x], d[u] + 1);
            compute_distances(g, x, v, d);
        }
    }
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const graph_t& g)
{
    const size_t n = g.size();

    std::vector<size_t> c;
    {
        std::vector<unsigned> v(n);
        find_cycle(g, 0, 0, v, c);
    }

    std::vector<unsigned> d(n, ~0u);
    {
        for (const size_t x : c)
            d[x] = 0;

        std::vector<bool> v(n);
        compute_distances(g, c[0], v, d);
    }

    answer(d);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    graph_t g(n);
    for (size_t i = 0; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    solve(g);

    return 0;
}
