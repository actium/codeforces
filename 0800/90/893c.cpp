#include <iostream>
#include <vector>

using integer = unsigned long long;

const unsigned oo = ~0u;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer v)
{
    std::cout << v << '\n';
}

unsigned dfs(const std::vector<std::vector<size_t>>& g, const std::vector<unsigned>& c, std::vector<unsigned>& v, size_t u)
{
    v[u] = c[u];

    for (const size_t x : g[u]) {
        if (v[x] == oo)
            v[u] = std::min(v[u], dfs(g, c, v, x));
    }

    return v[u];
}

void solve(const std::vector<std::vector<size_t>>& g, const std::vector<unsigned>& c)
{
    const size_t n = g.size();

    integer s = 0;

    std::vector<unsigned> v(n, oo);
    for (size_t i = 0; i < n; ++i) {
        if (v[i] == oo)
            s += dfs(g, c, v, i);
    }

    answer(s);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> c(n);
    std::cin >> c;

    std::vector<std::vector<size_t>> g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned x, y;
        std::cin >> x >> y;
        --x, --y;

        g[x].push_back(y);
        g[y].push_back(x);
    }

    solve(g, c);

    return 0;
}
