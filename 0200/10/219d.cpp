#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<std::pair<size_t, size_t>>>;

void answer(unsigned u, const std::vector<size_t>& v)
{
    std::cout << u << '\n';

    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << 1+x;
        separator = " ";
    }
    std::cout << '\n';
}

void traverse_1(const graph_t& g, size_t u, size_t p, std::vector<unsigned>& c)
{
    for (const auto& e : g[u]) {
        if (e.first != p) {
            traverse_1(g, e.first, u, c);
            c[u] += c[e.first] + (e.second != u);
        }
    }
}

void traverse_2(const graph_t& g, size_t u, size_t p, std::vector<unsigned>& c)
{
    for (const auto& e : g[u]) {
        if (e.first != p) {
            c[e.first] = c[u] + (e.second == u ? 1 : -1);
            traverse_2(g, e.first, u, c);
        }
    }
}

void solve(const graph_t& g)
{
    const size_t n = g.size();

    std::vector<unsigned> c(n);
    traverse_1(g, 0, 0, c);
    traverse_2(g, 0, 0, c);

    size_t x = 0;
    for (size_t i = 1; i < n; ++i) {
        if (c[i] < c[x])
            x = i;
    }

    std::vector<size_t> p;
    for (size_t i = 0; i < n; ++i) {
        if (c[i] == c[x])
            p.push_back(i);
    }

    answer(c[x], p);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned s, t;
        std::cin >> s >> t;

        g[s-1].emplace_back(t-1, s-1);
        g[t-1].emplace_back(s-1, s-1);
    }

    solve(g);

    return 0;
}
