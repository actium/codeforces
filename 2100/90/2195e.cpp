#include <iostream>
#include <vector>

constexpr unsigned M = 1'000'000'007;

using graph_t = std::vector<std::vector<size_t>>;

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

unsigned explore(const graph_t& g, size_t s, std::vector<unsigned>& v)
{
    for (const size_t t : g[s])
        v[s-1] += explore(g, t, v) + 1;

    return v[s-1];
}

void propagate(const graph_t& g, size_t s, std::vector<unsigned>& v)
{
    for (const size_t t : g[s]) {
        v[t-1] = (v[t-1] + v[s-1]) % M;
        propagate(g, t, v);
    }
}

void solve(const graph_t& g)
{
    const size_t n = g.size() - 1;

    std::vector<unsigned> v(n, 1);
    explore(g, 1, v);
    propagate(g, 1, v);

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    graph_t g(1+n);
    for (size_t i = 1; i <= n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        if (u != 0 && v != 0) {
            g[i].push_back(u);
            g[i].push_back(v);
        }
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
