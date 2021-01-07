#include <iostream>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void dfs(const std::vector<std::vector<size_t>>& g, std::vector<unsigned>& c, size_t i, unsigned x)
{
    c[i] = x;

    for (const size_t v : g[i]) {
        if (c[v] == 0)
            dfs(g, c, v, 3-x);
    }
}

void solve(const std::vector<std::vector<size_t>>& g)
{
    const size_t n = g.size();

    std::vector<unsigned> c(n);
    dfs(g, c, 0, 1);

    unsigned f[2] = {};
    for (const unsigned x : c)
        ++f[x-1];

    answer(f[0] * f[1] - n + 1);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<size_t>> g(n);
    for (size_t i = 0; i < n-1; ++i) {
        unsigned u, v;
        std::cin >> u >> v;
        --u, --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    solve(g);

    return 0;
}

