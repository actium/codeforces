#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

void find_farthest(const graph_t& g, size_t u, size_t p, unsigned d, std::pair<unsigned, size_t>& x)
{
    if (d > x.first) {
        x.first = d;
        x.second = u;
    }

    for (const size_t v : g[u]) {
        if (v != p)
            find_farthest(g, v, u, d + 1, x);
    }
}

std::pair<unsigned, unsigned> count(const graph_t& g, size_t u, size_t p, unsigned d, unsigned k)
{
    std::pair<unsigned, unsigned> r = { 1, 0 };
    {
        unsigned c = (1 + d > k);
        for (const size_t v : g[u]) {
            if (v == p)
                continue;

            const std::pair<unsigned, unsigned> s = count(g, v, u, d + 1, k);
            r.first = std::max(r.first, s.first + 1);
            r.second += s.second;

            c += (s.first + 1 > k);
        }

        r.second += (c > 1);
    }
    return r;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const graph_t& g, unsigned k)
{
    std::pair<unsigned, size_t> s = { 0, 0 };
    find_farthest(g, 0, 0, 0, s);

    answer(count(g, s.second, s.second, 0, k).second);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

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
