#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

constexpr unsigned M = 998244353;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void explore(const graph_t& g, size_t u, unsigned k, std::vector<std::vector<size_t>>& q)
{
    if (q.size() <= k)
        q.resize(k + 1);

    q[k].push_back(u);

    for (const size_t v : g[u])
        explore(g, v, k + 1, q);
}

void solve(const graph_t& g)
{
    const size_t n = g.size();

    std::vector<std::vector<size_t>> q;
    explore(g, 0, 0, q);

    std::vector<unsigned> c(n);
    for (auto it = q.rbegin(); std::next(it) != q.rend(); ++it) {
        unsigned d = 0;
        for (const size_t u : *it) {
            c[u] = c[0] + 1;

            if (u != 0) {
                for (const size_t v : g[u])
                    c[u] = (M + c[u] - c[v]) % M;
            }

            d = (d + c[u]) % M;
        }
        c[0] = d;
    }

    answer((c[0] + 1) % M);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned p;
        std::cin >> p;

        g[p-1].push_back(i);
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
