#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

std::pair<unsigned, unsigned> count(const graph_t& g, size_t u, unsigned d)
{
    unsigned k = 1;

    std::pair<unsigned, unsigned> b = { d, d };
    for (const size_t v : g[u]) {
        const auto t = count(g, v, d + 1);
        if (t.second > b.second)
            b.second = t.second;

        if (b.second > b.first)
            std::swap(b.first, b.second);

        k += t.first;
    }

    return { k + std::min(b.first, b.second) - d, std::max(b.first, b.second) };
}

void solve(const graph_t& g)
{
    answer(count(g, 0, 0).first);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned p;
        std::cin >> p;

        g[p-1].push_back(i);
    }

    solve(g);
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
