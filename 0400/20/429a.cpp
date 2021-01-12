#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<size_t>& v)
{
    std::cout << v.size() << '\n';

    for (const size_t x : v)
        std::cout << 1+x << '\n';
}

void dfs(const std::vector<std::vector<size_t>>& g, const std::vector<unsigned>& s, const std::vector<unsigned>& t,
        size_t u, size_t q, unsigned x, unsigned y, std::vector<size_t>& p)
{
    if (s[u] ^ x != t[u]) {
        p.push_back(u);
        x ^= 1;
    }

    for (const size_t v : g[u]) {
        if (v != q)
            dfs(g, s, t, v, u, y, x, p);
    }
}

void solve(const std::vector<std::vector<size_t>>& g, std::vector<unsigned>& s, const std::vector<unsigned>& t)
{
    std::vector<size_t> p;
    dfs(g, s, t, 0, 0, 0, 0, p);
    answer(p);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<size_t>> g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;
        --u, --v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    std::vector<unsigned> s(n), t(n);
    std::cin >> s >> t;

    solve(g, s, t);

    return 0;
}

