#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;
using integer = long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<integer>& v)
{
    const char* separator = "";
    for (const integer x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void traverse(const graph_t& g, const std::vector<unsigned>& a, size_t u, size_t p, std::vector<std::pair<integer, integer>>& b)
{
    b[u] = {
        std::min<integer>(a[u], a[u] - b[p].second),
        std::max<integer>(a[u], a[u] - b[p].first)
    };

    for (const size_t v : g[u]) {
        if (v != p)
            traverse(g, a, v, u, b);
    }
}

void solve(const graph_t& g, const std::vector<unsigned>& a)
{
    const size_t n = g.size();

    std::vector<std::pair<integer, integer>> b(n);
    traverse(g, a, 0, 0, b);

    std::vector<integer> d(n);
    for (size_t i = 0; i < n; ++i)
        d[i] = b[i].second;

    answer(d);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    solve(g, a);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
