#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

std::pair<unsigned, unsigned> count(const graph_t& g, size_t u, size_t p, unsigned x)
{
    std::pair<unsigned, unsigned> s = { 1, 0 };
    for (const size_t v : g[u]) {
        if (v == p)
            continue;

        const std::pair<unsigned, unsigned> t = count(g, v, u, x);
        if (t.first < x)
            s.first += t.first;
        else
            ++s.second;

        s.second += t.second;
    }
    return s;
}

void solve(const graph_t& g, size_t k)
{
    const size_t n = g.size();

    const auto check = [&](unsigned x) {
        const std::pair<unsigned, unsigned> t = count(g, 0, 0, x);
        return t.second > k || t.second == k && t.first >= x;
    };

    unsigned lb = 0, ub = n;
    while (lb + 1 < ub) {
        const unsigned mid = (lb + ub) / 2;
        (check(mid) ? lb : ub) = mid;
    }

    answer(lb);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    solve(g, k);
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
