#include <algorithm>
#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

unsigned count(const graph_t& g, size_t u, size_t p)
{
    unsigned k = 1;
    for (const size_t v : g[u]) {
        if (v != p)
            k += count(g, v, u);
    }
    return k;
}

void answer(const std::vector<std::pair<unsigned, unsigned>>& v)
{
    std::cout << v.size() << '\n';

    for (const std::pair<unsigned, unsigned>& x : v)
        std::cout << x.first << ' ' << x.second << '\n';
}

void solve(const graph_t& g)
{
    const size_t n = g.size();

    std::vector<std::pair<unsigned, unsigned>> s;
    for (size_t i = 0; i < n; ++i) {
        const size_t k = g[i].size();
        if (k < 2)
            continue;

        std::vector<unsigned> c(k);
        for (size_t j = 0; j < k; ++j)
            c[j] = count(g, g[i][j], i);

        std::vector<bool> dp(n);
        dp[0] = true;
        for (const unsigned x : c) {
            for (size_t p = n - 1; p >= x; --p)
                dp[p] = dp[p] || dp[p-x];
        }

        for (size_t j = 1; j < n - 1; ++j) {
            if (dp[j])
                s.emplace_back(j, n - 1 - j);
        }
    }

    std::sort(s.begin(), s.end());
    s.erase(std::unique(s.begin(), s.end()), s.end());

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned x, y;
        std::cin >> x >> y;

        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }

    solve(g);

    return 0;
}
