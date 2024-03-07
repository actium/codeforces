#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void search(const graph_t& g, size_t u, size_t p, std::vector<unsigned>& dp, unsigned& d)
{
    for (const size_t v : g[u]) {
        if (v == p)
            continue;

        search(g, v, u, dp, d);

        d = std::max(d, dp[u] + dp[v] + 1);
        dp[u] = std::max(dp[u], dp[v] + 1);
    }
}

void solve(const graph_t& g)
{
    unsigned d = 0;
    {
        std::vector<unsigned> dp(g.size());
        search(g, 0, 0, dp, d);
    }
    answer(d);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    graph_t g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned a, b;
        std::cin >> a >> b;
        --a, --b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    solve(g);

    return 0;
}
