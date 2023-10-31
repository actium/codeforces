#include <iostream>
#include <set>
#include <vector>

using edge_t = std::pair<unsigned, unsigned>;

void solve(const std::vector<edge_t>& edges)
{
    const size_t n = edges.size() + 1;

    std::vector<std::set<size_t>> g(n);
    for (size_t i = 0; i + 1 < n; ++i) {
        const edge_t& e = edges[i];
        g[e.first-1].insert(i);
        g[e.second-1].insert(i);
    }

    std::vector<size_t> q;
    for (size_t i = 0; i < n; ++i) {
        if (g[i].size() == 1)
            q.push_back(i);
    }

    const auto drop = [&](size_t u, size_t i) {
        g[u].erase(i);

        if (g[u].size() == 1)
            q.push_back(u);
    };

    std::vector<unsigned> v(n - 1);
    for (unsigned k = 0; k + 1 < n; ++k) {
        const size_t i = *g[q[k]].begin();
        v[i] = k;
        drop(edges[i].first - 1, i);
        drop(edges[i].second - 1, i);
    }

    for (const unsigned x : v)
        std::cout << x << '\n';
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<edge_t> edges(n - 1);
    for (edge_t& e : edges)
        std::cin >> e.first >> e.second;

    solve(edges);

    return 0;
}
