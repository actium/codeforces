#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;
using integer = unsigned long long;

void compute_distances(const graph_t& g, size_t u, size_t p, std::vector<unsigned>& d)
{
    for (const size_t v : g[u]) {
        if (v != p) {
            d[v] = d[u] + 1;
            compute_distances(g, v, u, d);
        }
    }
}

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const graph_t& g, unsigned k, unsigned c)
{
    const size_t n = g.size();

    std::vector<unsigned> d(n);
    compute_distances(g, 0, 0, d);

    size_t s = 0;
    for (size_t i = 1; i < n; ++i) {
        if (d[i] > d[s])
            s = i;
    }

    if (c >= k)
        return answer(1ull * d[s] * k);

    std::vector<unsigned> e(n);
    compute_distances(g, s, s, e);

    integer v = 0;
    for (size_t i = 0; i < n; ++i)
        v = std::max<long long>(v, 1ll * e[i] * k - 1ll * std::min(d[s], d[i]) * c);

    answer(v);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k, c;
    std::cin >> k >> c;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    solve(g, k, c);
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
