#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const graph_t& g)
{
    const size_t n = g.size();

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i)
        k += (g[i].size() == 1);

    unsigned d = 0;
    for (size_t i = 0; i < n; ++i) {
        unsigned c = (g[i].size() == 1);
        for (const size_t v : g[i])
            c += g[v].size() == 1;

        d = std::max(d, c);
    }

    answer(k - d);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    graph_t g(n);
    while (--n != 0) {
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
