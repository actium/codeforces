#include <iostream>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<std::vector<size_t>>& g)
{
    const size_t n = g.size();

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        if (g[i].size() == 1)
            ++k;
    }

    answer((k + 1) / 2);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<size_t>> g(n);
    for (size_t i = 1; i < n; ++i) {
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
