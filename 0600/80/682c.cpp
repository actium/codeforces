#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<std::pair<size_t, int>>>;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned count(const graph_t& g, size_t u, long long w, const std::vector<unsigned>& a)
{
    if (a[u] < w)
        return 0;

    unsigned k = 1;
    for (const auto& [v, c] : g[u])
        k += count(g, v, std::max(w + c, 0LL), a);

    return k;
}

void solve(const graph_t& g, const std::vector<unsigned>& a)
{
    answer(g.size() - count(g, 0, 0, a));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        int p, c;
        std::cin >> p >> c;

        g[p-1].emplace_back(i, c);
    }

    solve(g, a);

    return 0;
}
