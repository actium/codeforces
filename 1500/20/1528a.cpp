#include <iostream>
#include <vector>

using integer = unsigned long long;

using graph_t = std::vector<std::vector<size_t>>;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

unsigned delta(unsigned x, unsigned y)
{
    return std::max(x, y) - std::min(x, y);
}

std::pair<integer, integer> search(const graph_t& g, size_t u, size_t p, const std::vector<std::pair<unsigned, unsigned>>& s)
{
    std::pair<integer, integer> v = { 0, 0 };
    for (const size_t x : g[u]) {
        if (x == p)
            continue;

        const std::pair<integer, integer> c = search(g, x, u, s);

        const integer d1 = delta(s[u].first, s[x].first) + c.first;
        const integer d2 = delta(s[u].second, s[x].first) + c.first;
        const integer d3 = delta(s[u].first, s[x].second) + c.second;
        const integer d4 = delta(s[u].second, s[x].second) + c.second;

        v.first += std::max(d1, d3);
        v.second += std::max(d2, d4);
    }

    return v;
}

void solve(graph_t& g, const std::vector<std::pair<unsigned, unsigned>>& s)
{
    const std::pair<integer, integer> v = search(g, 0, 0, s);

    answer(std::max(v.first, v.second));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::pair<unsigned, unsigned>> s(n);
    std::cin >> s;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    solve(g, s);
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
