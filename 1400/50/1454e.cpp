#include <iostream>
#include <set>
#include <vector>

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(std::vector<std::set<size_t>>& g)
{
    const size_t n = g.size();

    std::vector<size_t> q;
    for (size_t i = 0; i < n; ++i) {
        if (g[i].size() == 1)
            q.push_back(i);
    }

    std::vector<unsigned> c(n, 1);
    for (size_t i = 0; i < q.size(); ++i) {
        const size_t u = q[i], v = *g[u].begin();
        c[v] += c[u];
        c[u] = 0;

        g[v].erase(u);
        g[u].clear();

        if (g[v].size() == 1)
            q.push_back(v);
    }

    unsigned long long k = 0;
    for (size_t i = 0; i < n; ++i) {
        k += c[i] * (c[i] - 1ull) / 2;
        k += 1ull * c[i] * (n - c[i]);
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::set<size_t>> g(n);
    for (size_t i = 0; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;
        --u, --v;

        g[u].insert(v);
        g[v].insert(u);
    }

    solve(g);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

