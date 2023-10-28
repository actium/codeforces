#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

bool paint(const graph_t& g, size_t u, unsigned k, std::vector<unsigned>& c)
{
    if (c[u] != 0)
        return c[u] == k;

    c[u] = k;

    for (const size_t v : g[u]) {
        if (!paint(g, v, 3 - k, c))
            return false;
    }
    return true;
}

std::ostream& operator <<(std::ostream& output, const std::vector<unsigned>& v)
{
    output << v.size() << '\n';

    const char* separator = "";
    for (const unsigned x : v) {
        output << separator << x;
        separator = " ";
    }

    return output;
}

void answer(const std::vector<unsigned>& x, const std::vector<unsigned>& y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const graph_t& g)
{
    const size_t n = g.size();

    std::vector<unsigned> c(n);
    for (size_t i = 0; i < n; ++i) {
        if (c[i] == 0 && !paint(g, i, 1, c))
            return no_answer();
    }

    std::vector<unsigned> v[2];
    for (size_t i = 0; i < n; ++i)
        v[c[i]-1].push_back(1 + i);

    answer(v[0], v[1]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    graph_t g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    solve(g);

    return 0;
}
