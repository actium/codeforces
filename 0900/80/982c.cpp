#include <iostream>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

std::pair<unsigned, unsigned> solve(const std::vector<std::vector<size_t>>& g, size_t u, size_t p)
{
    std::pair<unsigned, unsigned> s = { 0, 1 };
    for (const size_t x : g[u]) {
        if (x == p)
            continue;

        const std::pair<unsigned, unsigned> t = solve(g, x, u);
        s.first += t.first + (t.second % 2 == 0);
        s.second += t.second % 2;
    }
    return s;
}

void solve(const std::vector<std::vector<size_t>>& g)
{
    const std::pair<unsigned, unsigned> s = solve(g, 0, 0);
    if (s.second % 2 == 1)
        return no_answer();

    answer(s.first);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

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

    return 0;
}
