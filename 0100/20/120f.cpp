#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void dfs(const graph_t& g, size_t u, size_t p, std::vector<unsigned>& dp, unsigned& d)
{
    for (const size_t v : g[u]) {
        if (v == p)
            continue;

        dfs(g, v, u, dp, d);

        d = std::max(d, dp[u] + dp[v] + 1);
        dp[u] = std::max(dp[u], dp[v] + 1);
    }
}

unsigned diameter(const graph_t& g)
{
    unsigned d = 0;

    std::vector<unsigned> dp(g.size());
    dfs(g, 0, 0, dp, d);

    return d;
}

void solve(const std::vector<graph_t>& g)
{
    unsigned k = 0;
    for (const graph_t& t : g)
        k += diameter(t);

    answer(k);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    size_t n;
    std::cin >> n;

    std::vector<graph_t> g(n);
    for (size_t i = 0; i < n; ++i) {
        size_t k;
        std::cin >> k;

        for (g[i].resize(k); k > 1; --k) {
            unsigned a, b;
            std::cin >> a >> b;

            g[i][a-1].push_back(b-1);
            g[i][b-1].push_back(a-1);
        }
    }

    solve(g);

    return 0;
}
