#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

void answer(double x)
{
    std::cout << std::fixed << x << '\n';
}

void solve(const graph_t& g, unsigned s)
{
    unsigned k = 0;
    for (const auto& v : g)
        k += (v.size() == 1);

    answer(2.0 * s / k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned s;
    std::cin >> s;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned a, b;
        std::cin >> a >> b;

        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }

    solve(g, s);

    return 0;
}
