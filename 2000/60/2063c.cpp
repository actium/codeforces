#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using graph_t = std::vector<std::set<size_t>>;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const graph_t& g)
{
    const size_t n = g.size();

    std::vector<size_t> p(n);
    for (size_t i = 0; i < n; ++i)
        p[i] = i;

    std::sort(p.begin(), p.end(), [&](size_t i, size_t j) {
        return g[i].size() != g[j].size() ? g[i].size() > g[j].size() : i < j;
    });

    size_t k = 0;
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = i + 1; j < n; ++j) {
            const size_t d = 1 + (g[p[i]].count(p[j]) != 0);
            k = std::max(k, g[p[i]].size() + g[p[j]].size() - d);
        }
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

        g[u-1].insert(v-1);
        g[v-1].insert(u-1);
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
