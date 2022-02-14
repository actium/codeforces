#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

void answer(const std::vector<std::pair<size_t, size_t>>& v)
{
    std::cout << "Yes" << '\n';
    std::cout << v.size() << '\n';

    for (const std::pair<size_t, size_t>& x : v)
        std::cout << 1+x.first << ' ' << 1+x.second << '\n';
}

void no_answer()
{
    std::cout << "No" << '\n';
}

bool search(const graph_t& g, size_t v, size_t p, size_t& x)
{
    x = v;

    if (g[v].size() == 2)
        return search(g, g[v][0] ^ g[v][1] ^ p, v, x);

    return g[v].size() == 1;
}

void solve(const graph_t& g)
{
    const size_t n = g.size();

    size_t x = 0;
    for (size_t i = 1; i < n; ++i) {
        if (g[i].size() > g[x].size())
            x = i;
    }

    std::vector<std::pair<size_t, size_t>> r;
    for (const size_t a : g[x]) {
        r.emplace_back(x, n);
        if (!search(g, a, x, r.back().second))
            return no_answer();
    }

    answer(r);
}

int main()
{
    size_t n;
    std::cin >> n;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned a, b;
        std::cin >> a >> b;

        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    solve(g);

    return 0;
}
