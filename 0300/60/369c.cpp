#include <algorithm>
#include <iostream>
#include <vector>

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1 + x;
        separator = " ";
    }
    std::cout << '\n';
}

struct Edge {
    size_t v;
    unsigned t;
    size_t x;
};

using graph_t = std::vector<std::vector<Edge>>;

std::pair<bool, size_t> prepare(graph_t& g, size_t u, size_t p)
{
    std::pair<bool, size_t> x = { false, u };
    for (size_t i = 0; i < g[u].size(); ++i) {
        if (g[u][i].v == p) {
            g[u][i--] = g[u].back();
            g[u].pop_back();
        } else {
            const std::pair<bool, size_t> s = prepare(g, g[u][i].v, u);
            g[u][i].x = s.second;

            if (s.first || g[u][i].t == 2)
                x = std::make_pair(true, g[u][i].x);
        }
    }
    return x;
}

void solve(graph_t& g)
{
    const size_t n = g.size();

    prepare(g, 0, 0);

    std::vector<size_t> s;
    for (size_t i = 0; i < n; ++i) {
        for (const Edge& e : g[i]) {
            if (e.t == 2)
                s.push_back(e.x);
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
        unsigned x, y, t;
        std::cin >> x >> y >> t;

        g[x-1].push_back({y-1, t});
        g[y-1].push_back({x-1, t});
    }

    solve(g);

    return 0;
}
