#include <iostream>
#include <set>
#include <vector>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<std::set<size_t>>& g)
{
    const size_t n = g.size();

    unsigned k = 0;
    while (true) {
        std::vector<size_t> q;
        for (size_t i = 0; i < n; ++i) {
            if (g[i].size() == 1)
                q.push_back(i);
        }

        if (q.empty())
            break;

        for (const size_t u : q) {
            const size_t v = *g[u].begin();
            g[v].erase(u), g[u].erase(v);
        }

        ++k;
    }

    answer(k);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::set<size_t>> g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned a, b;
        std::cin >> a >> b;
        --a, --b;

        g[a].insert(b);
        g[b].insert(a);
    }

    solve(g);

    return 0;
}

