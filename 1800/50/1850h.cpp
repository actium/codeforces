#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<std::pair<size_t, int>>>;
using integer = long long;

bool check(const graph_t& g, size_t u, integer p, std::vector<std::pair<bool, integer>>& v)
{
    if (!v[u].first) {
        v[u].first = true;
        v[u].second = p;

        for (const auto& e : g[u]) {
            if (!check(g, e.first, p + e.second, v))
                return false;
        }
    }
    return v[u].second == p;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const graph_t& g)
{
    const size_t n = g.size();

    std::vector<std::pair<bool, integer>> v(n);
    for (size_t i = 0; i < n; ++i) {
        if (!v[i].first && !check(g, i, 0, v))
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    graph_t g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned a, b;
        std::cin >> a >> b;

        int d;
        std::cin >> d;

        g[a-1].emplace_back(b-1, d);
        g[b-1].emplace_back(a-1, -d);
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
