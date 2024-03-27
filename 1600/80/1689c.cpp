#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void prepare(graph_t& g, size_t u, size_t p, std::vector<unsigned>& s)
{
    s[u] = 1;

    for (size_t& v : g[u]) {
        if (v == p)
            std::swap(v, g[u].back());

        if (v != p) {
            prepare(g, v, u, s);
            s[u] += s[v];
        }
    }

    if (g[u].back() == p)
        g[u].pop_back();
}

unsigned search(const graph_t& g, size_t u, const std::vector<unsigned>& s)
{
    if (g[u].size() == 0)
        return 0;

    if (g[u].size() == 1)
        return s[u] - 2;

    const size_t x = g[u][0], y = g[u][1];
    return std::max(s[x] - 1 + search(g, y, s), s[y] - 1 + search(g, x, s));
}

void solve(graph_t& g)
{
    const size_t n = g.size();

    std::vector<unsigned> s(n);
    prepare(g, 0, 0, s);

    answer(search(g, 0, s));
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