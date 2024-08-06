#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

constexpr unsigned M = 998244353;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

std::pair<unsigned, unsigned> count(const graph_t& g, size_t u, unsigned x, std::vector<unsigned>& c)
{
    c[u] = x;
    x ^= 3;

    std::pair<unsigned, unsigned> k = { x^0, x^3 };
    for (const size_t v : g[u]) {
        if (c[v] == x)
            continue;

        if (c[v] != 0)
            return { 0, 0 };

        const std::pair<unsigned, unsigned> q = count(g, v, x, c);
        k.first = 1ull * k.first * q.first % M;
        k.second = 1ull * k.second * q.second % M;
    }
    return k;
}

void solve(const graph_t& g)
{
    const size_t n = g.size();

    unsigned k = 1;
    {
        std::vector<unsigned> c(n);
        for (size_t i = 0; i < n; ++i) {
            if (c[i] != 0)
                continue;

            const std::pair<unsigned, unsigned> q = count(g, i, 1, c);
            k = 1ull * k * (q.first + q.second) % M;
        }
    }
    answer(k);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    graph_t g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
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
