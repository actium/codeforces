#include <iostream>
#include <set>
#include <vector>

using integer = unsigned long long;

constexpr integer oo = ~integer(0);

struct Edge {
    unsigned t;
    unsigned w;
};

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        std::cout << separator << *it;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::vector<std::vector<Edge>>& g)
{
    const size_t n = g.size();

    std::vector<std::pair<integer, unsigned>> d(n, {oo, n});
    std::set<std::pair<integer, unsigned>> q;

    const auto enqueue = [&](unsigned u, unsigned p, integer w) {
        if (w >= d[u].first)
            return;

        if (d[u].first != oo)
            q.erase(std::make_pair(w, u));

        d[u].first = w;
        d[u].second = p;
        q.emplace(w, u);
    };

    enqueue(0, n, 0);
    while (!q.empty() && q.begin()->second != n-1) {
        const std::pair<integer, unsigned> p = *q.begin();
        q.erase(q.begin());

        for (const Edge& e : g[p.second]) {
            if (e.t != p.second)
                enqueue(e.t, p.second, p.first + e.w);
        }
    }

    if (q.empty())
        return no_answer();

    std::vector<unsigned> p;
    for (unsigned x = n - 1; x != n; x = d[x].second)
        p.push_back(1 + x);

    answer(p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<Edge>> g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned u, v, w;
        std::cin >> u >> v >> w;

        if (u != v) {
            g[u-1].push_back({v-1, w});
            g[v-1].push_back({u-1, w});
        }
    }

    solve(g);

    return 0;
}
