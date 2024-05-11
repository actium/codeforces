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

void answer(const char* x)
{
    std::cout << x << '\n';
}

unsigned explore(const graph_t& g, size_t u, size_t p)
{
    for (const size_t v : g[u]) {
        if (v != p)
            return 1 + explore(g, v, u);
    }
    return 1;
}

void solve(const graph_t& g, const std::vector<unsigned>& t)
{
    const size_t s = t[0] - 1;

    for (const size_t v : g[s]) {
        if (explore(g, v, s) % 2 == 1)
            return answer("Ron");
    }

    answer("Hermione");
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, t;
    std::cin >> n >> t;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    std::vector<unsigned> u(t);
    std::cin >> u;

    solve(g, u);

    return 0;
}
