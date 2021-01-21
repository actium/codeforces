#include <iostream>
#include <vector>

void answer(bool v)
{
    constexpr const char* s[2] = { "no", "yes" };
    std::cout << s[v] << '\n';
}

bool check(const std::vector<std::vector<size_t>>& g, size_t i, size_t p, std::vector<bool>& v)
{
    v[i] = true;

    for (const size_t j : g[i]) {
        if (j != p && (v[j] || !check(g, j, i, v)))
            return false;
    }

    return true;
}

void solve(const std::vector<std::vector<size_t>>& g)
{
    const size_t n = g.size();

    std::vector<bool> v(n);
    for (size_t i = 0; i < n; ++i) {
        if (!v[i] && (g[i].empty() || !check(g, i, n, v)))
            return answer(false);
    }

    answer(true);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<std::vector<size_t>> g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned a, b;
        std::cin >> a >> b;
        --a, --b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    solve(g);

    return 0;
}

