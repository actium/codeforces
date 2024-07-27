#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void infinity()
{
    std::cout << -1 << '\n';
}

bool sort(const graph_t& g, size_t u, std::vector<unsigned>& v, std::vector<size_t>& p)
{
    if (v[u] == 0) {
        v[u] = 1;
        for (const size_t x : g[u]) {
            if (!sort(g, x, v, p))
                return false;
        }
        p.push_back(u);
        v[u] = 2;
    }
    return v[u] == 2;
}

void count(const graph_t& g, size_t u, const std::string& s, std::vector<std::vector<unsigned>>& f)
{
    ++f[u][26];

    for (const size_t x : g[u]) {
        if (f[x][26] == 0)
            count(g, x, s, f);

        for (size_t i = 0; i < 26; ++i)
            f[u][i] = std::max(f[u][i], f[x][i]);
    }

    ++f[u][s[u]-'a'];
}

void solve(const graph_t& g, const std::string& s)
{
    const size_t n = g.size();

    std::vector<size_t> p;
    {
        std::vector<unsigned> v(n);
        for (size_t i = 0; i < n; ++i) {
            if (!sort(g, i, v, p))
                return infinity();
        }
    }

    unsigned k = 0;
    {
        std::vector<std::vector<unsigned>> f(n, std::vector<unsigned>(27));
        for (auto it = p.rbegin(); it != p.rend(); ++it) {
            if (f[*it][26] != 0)
                continue;

            count(g, *it, s, f);

            for (size_t i = 0; i < 26; ++i)
                k = std::max(k, f[*it][i]);
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    graph_t g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
    }

    solve(g, s);

    return 0;
}
