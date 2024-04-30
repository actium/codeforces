#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

constexpr unsigned oo = ~0u;

void compute_distances(const graph_t& g, size_t s, std::vector<unsigned>& d)
{
    const size_t n = g.size();

    std::vector<bool> p(n);
    std::queue<size_t> q;

    const auto enqueue = [&](size_t v, unsigned k) {
        if (d[v] <= k)
            return;

        d[v] = k;

        if (!p[v]) {
            q.push(v);
            p[v] = true;
        }
    };

    const auto dequeue = [&] {
        const size_t v = q.front();
        q.pop();
        p[v] = false;
        return v;
    };

    enqueue(s, 0);
    while (!q.empty()) {
        const size_t v = dequeue();

        for (const size_t x : g[v])
            enqueue(x, d[v] + 1);
    }
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const graph_t& g, size_t s, size_t t)
{
    const size_t n = g.size();

    std::vector<unsigned> ds(n, oo);
    compute_distances(g, s, ds);

    std::vector<unsigned> dt(n, oo);
    compute_distances(g, t, dt);

    unsigned k = 0;
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (ds[i] + 1 + dt[j] < ds[t] || ds[j] + 1 + dt[i] < ds[t])
                continue;

            if (std::find(g[j].begin(), g[j].end(), i) == g[j].end())
                ++k;
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    unsigned s, t;
    std::cin >> s >> t;

    graph_t g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    solve(g, s-1, t-1);

    return 0;
}
