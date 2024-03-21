#include <algorithm>
#include <iostream>
#include <vector>

using integer = unsigned long long;

using graph_t = std::vector<std::vector<size_t>>;

void traverse(const graph_t& g, size_t u, size_t p, std::vector<std::pair<unsigned, unsigned>>& d)
{
    for (const size_t v : g[u]) {
        if (v != p) {
            d[v].first = d[u].first + 1;
            traverse(g, v, u, d);
            d[u].second += d[v].second;
        }
    }
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const graph_t& g, size_t k)
{
    const size_t n = g.size();

    std::vector<std::pair<unsigned, unsigned>> d(n, std::make_pair(1, 1));
    traverse(g, 0, 0, d);

    std::sort(d.begin(), d.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.second + rhs.first < rhs.second + lhs.first;
    });

    integer q = 0;
    for (size_t i = k; i < n; ++i)
        q += int(d[i].second - d[i].first);

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    solve(g, k);

    return 0;
}
