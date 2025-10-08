#include <algorithm>
#include <iostream>
#include <vector>

struct Edge {
    unsigned t;
    int d;
};

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void traverse(const std::vector<std::vector<Edge>>& g, size_t u, size_t p, std::vector<long long>& w)
{
    for (const Edge& e : g[u]) {
        if (e.t != p) {
            w[e.t] = w[u] + e.d;
            traverse(g, e.t, u, w);
        }
    }
}

void solve(const std::vector<std::vector<Edge>>& g)
{
    const size_t n = g.size();

    std::vector<long long> w(n);
    traverse(g, 0, 0, w);

    std::vector<size_t> q(n);
    for (size_t i = 0; i < n; ++i)
        q[i] = i;

    std::sort(q.begin(), q.end(), [&](size_t i, size_t j) {
        return w[i] < w[j];
    });

    std::vector<unsigned> p(n);
    for (size_t i = 0; i < n; ++i)
        p[q[i]] = i + 1;

    answer(p);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<Edge>> g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v, x, y;
        std::cin >> u >> v >> x >> y;

        g[u-1].push_back({ v-1, y - x });
        g[v-1].push_back({ u-1, x - y });
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
