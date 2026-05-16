#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned count(const graph_t& g, size_t s, std::vector<unsigned>& c)
{
    std::vector<size_t> q;

    const auto enqueue = [&](size_t u, unsigned k) {
        if ((c[u] & k) != k) {
            c[u] |= k;
            q.push_back(u);
        }
    };

    enqueue(s, 1);

    unsigned counts[4] = {};
    for (size_t i = 0; i < q.size(); ++i) {
        const size_t u = q[i];
        ++counts[c[u]];

        for (const size_t v : g[u])
            enqueue(v, std::max(1u, c[u] ^ 3));
    }
    return counts[3] == 0 ? std::max(counts[1], counts[2]) : 0;
}

void solve(const graph_t & g)
{
    const size_t n = g.size();

    unsigned k = 0;
    {
        std::vector<unsigned> c(n);
        for (size_t i = 0; i < n; ++i) {
            if (c[i] == 0)
               k += count(g, i, c);
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
