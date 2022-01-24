#include <algorithm>
#include <iostream>
#include <vector>

using edge_t = std::pair<unsigned, unsigned>;

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

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void assign_weights(const std::vector<std::vector<std::pair<size_t, size_t>>>& g, size_t v, size_t p, unsigned x, std::vector<unsigned>& w)
{
    for (const auto& e : g[v]) {
        if (e.first == p)
            continue;

        w[e.second] = x;
        assign_weights(g, e.first, v, x ^ 1, w);
    }
}

void solve(const std::vector<edge_t>& e)
{
    const size_t n = e.size() + 1;

    std::vector<unsigned> d(n);
    for (const edge_t& x : e) {
        if (++d[x.first-1] == 3 || ++d[x.second-1] == 3)
            return no_answer();
    }

    std::vector<std::vector<std::pair<size_t, size_t>>> g(n);
    for (size_t i = 0; i < n-1; ++i) {
        const size_t u = e[i].first - 1, v = e[i].second - 1;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }

    const size_t x = std::distance(d.cbegin(), std::min_element(d.cbegin(), d.cend()));

    std::vector<unsigned> w(n-1);
    assign_weights(g, x, x, 2, w);

    answer(w);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<edge_t> e(n-1);
    std::cin >> e;

    solve(e);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
