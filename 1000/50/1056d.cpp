#include <algorithm>
#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void count(const graph_t& g, size_t u, std::vector<unsigned>& c)
{
    if (g[u].empty())
        c[u] = 1;

    for (const size_t v : g[u]) {
        count(g, v, c);
        c[u] += c[v];
    }
}

void solve(const graph_t& g)
{
    const size_t n = g.size();

    std::vector<unsigned> c(n);
    count(g, 0, c);

    std::sort(c.begin(), c.end());
    answer(c);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned p;
        std::cin >> p;

        g[p-1].push_back(i);
    }

    solve(g);

    return 0;
}
