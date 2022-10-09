#include <iostream>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void traverse(const std::vector<std::vector<size_t>>& g, size_t u, std::vector<bool>& v, std::vector<size_t>& c)
{
    v[u] = true;

    for (const size_t a : g[u]) {
        if (!v[a])
            traverse(g, a, v, c);
    }

    c.push_back(u);
}

void solve(const std::vector<std::vector<size_t>>& g)
{
    const size_t n = g.size();

    unsigned k = 0;

    std::vector<bool> v(n);
    for (size_t i = 0; i < n; ++i) {
        if (v[i])
            continue;

        std::vector<size_t> c;
        traverse(g, i, v, c);
        if (c.size() < 3)
            continue;

        unsigned q = 0;
        for (const size_t u : c)
            q += (g[u].size() == 2);

        k += (q == c.size());
    }

    answer(k);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<size_t>> g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    solve(g);

    return 0;
}
