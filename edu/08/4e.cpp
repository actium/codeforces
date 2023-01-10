#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const graph_t& g)
{
    using edge_t = std::pair<size_t, size_t>;

    const size_t n = g.size();

    std::vector<edge_t> s;
    for (size_t i = 0; i < n; ++i) {
        if (g[i].size() < 3)
            continue;

        for (const size_t j : g[i]) {
            if (j < i || g[j].size() < 3)
                continue;

            s.emplace_back(i, j);
        }
    }

    std::vector<std::vector<bool>> x(n, std::vector<bool>(n));
    for (size_t i = 0; i < n; ++i) {
        for (const size_t j : g[i]) {
            x[i][j] = true;
            x[j][i] = true;
        }
    }

    const auto is_clique = [&](const edge_t& a, const edge_t& b) {
        return x[a.second][a.first]
            && x[b.first][a.first] && x[b.first][a.second]
            && x[b.second][a.first] && x[b.second][a.second] && x[b.second][b.first];
    };

    const size_t k = s.size();

    unsigned q = 0;
    for (size_t i = 1; i < k; ++i) {
        for (size_t j = 0; j < i; ++j)
            q += is_clique(s[i], s[j]);
    }

    answer(q / 3);
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
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
