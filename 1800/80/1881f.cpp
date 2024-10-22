#include <iostream>
#include <set>
#include <vector>

using graph_t = std::vector<std::set<size_t>>;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

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

unsigned diameter(const graph_t& g, size_t u)
{
    unsigned d = 0;
    {
        std::vector<unsigned> dp(g.size());
        search(g, u, u, dp, d);
    }
    return d;
}

void solve(graph_t& g, const std::vector<unsigned>& a)
{
    const size_t n = g.size();

    std::vector<bool> v(n);
    for (const unsigned x : a)
        v[x-1] = true;

    std::vector<size_t> q;
    for (size_t i = 0; i < n; ++i) {
        if (g[i].size() == 1 && !v[i])
            q.push_back(i);
    }

    for (size_t i = 0; i < q.size(); ++i) {
        const size_t u = q[i];

        for (const size_t x : g[u]) {
            g[x].erase(u);

            if (g[x].size() == 1 && !v[x])
                q.push_back(x);
        }

        g[u].clear();
    }

    answer((diameter(g, a[0]-1) + 1) / 2);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(k);
    std::cin >> a;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].insert(v-1);
        g[v-1].insert(u-1);
    }

    solve(g, a);
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
