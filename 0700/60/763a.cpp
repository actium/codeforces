#include <iostream>
#include <set>
#include <vector>

using graph_t = std::vector<std::set<size_t>>;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(size_t x)
{
    std::cout << "YES" << '\n';
    std::cout << 1 + x << '\n';
}

void no_answer()
{
    std::cout << "NO" << '\n';
}

void solve(graph_t& g, const std::vector<unsigned>& c)
{
    const size_t n = g.size();

    std::vector<size_t> q;
    for (size_t i = 0; i < n; ++i) {
        if (g[i].size() == 1)
            q.push_back(i);
    }

    for (size_t i = 0; i < q.size(); ++i) {
        const size_t u = q[i];
        if (g[u].empty())
            continue;

        const size_t v = *g[u].begin();
        if (c[u] != c[v])
            continue;

        g[u].clear();
        g[v].erase(u);

        if (g[v].size() == 1)
            q.push_back(v);
    }

    std::vector<size_t> p;
    for (size_t i = 0; i < n; ++i) {
        if (g[i].size() > 1)
            p.push_back(i);
    }

    if (p.size() > 1)
        return no_answer();

    answer(p.empty() ? q.back() : p[0]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].insert(v-1);
        g[v-1].insert(u-1);
    }

    std::vector<unsigned> c(n);
    std::cin >> c;

    solve(g, c);

    return 0;
}