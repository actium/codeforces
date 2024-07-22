#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

void answer(const std::vector<unsigned>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void paint(const graph_t& g, size_t u, unsigned c, std::vector<unsigned>& p)
{
    p[u] = c;

    for (const size_t v : g[u]) {
        if (p[v] == 2)
            paint(g, v, c^1, p);
    }
}

void solve(const graph_t& g)
{
    const size_t n = g.size();

    std::vector<unsigned> p(n, 2);
    paint(g, 0, 0, p);

    unsigned k = 0;
    for (const unsigned x : p)
        k += x;

    std::vector<unsigned> s;
    for (size_t i = 0; i < n; ++i) {
        if ((p[i] == 0) == (k > n/2))
            s.push_back(i+1);
    }

    answer(s);
}

void test_case()
{
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
