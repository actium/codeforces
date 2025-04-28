#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

void answer(const std::vector<size_t>& v)
{
    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const graph_t& g, size_t t)
{
    const size_t n = g.size();

    std::vector<unsigned> d(n);
    for (size_t i = 0; i < n; ++i)
        d[i] = g[i].size() + (i == t);

    std::vector<size_t> q;
    for (size_t i = 0; i < n; ++i) {
        if (d[i] == 1)
            q.push_back(i);
    }

    for (size_t i = 0; i < q.size(); ++i) {
        for (const size_t u : g[q[i]]) {
            if (--d[u] == 1)
                q.push_back(u);
        }
    }

    answer(q);
}

void test_case()
{
    unsigned n, s, t;
    std::cin >> n >> s >> t;

    graph_t g(n);
    for (unsigned i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    solve(g, t-1);
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
