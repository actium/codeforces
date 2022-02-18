#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned count(const graph_t& g, const std::vector<unsigned>& a, unsigned m, size_t v, size_t p, unsigned k)
{
    k = (a[v] == 1 ? k + 1 : 0);
    if (k > m)
        return 0;

    if (g[v].size() == 1 && v != 0)
        return 1;

    unsigned q = 0;
    for (const size_t u : g[v]) {
        if (u != p)
            q += count(g, a, m, u, v, k);
    }
    return q;
}

void solve(const graph_t& g, const std::vector<unsigned>& a, unsigned m)
{
    answer(count(g, a, m, 0, 0, 0));
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<unsigned> a(n);
    for (size_t i = 0; i < n; ++i)
        std::cin >> a[i];

    graph_t g(n);
    while (--n > 0) {
        unsigned x, y;
        std::cin >> x >> y;

        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }

    solve(g, a, m);

    return 0;
}
