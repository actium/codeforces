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

void answer(const std::vector<size_t>& v)
{
    const char* separator = "";
    for (const size_t x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
}

void solve(const graph_t& g, std::vector<unsigned>& a, size_t k)
{
    std::vector<size_t> d(k), q;

    const auto enqueue = [&](size_t x, size_t t) {
        if (a[x] != 0) {
            d[a[x]-1] = t;
            q.push_back(x);
            a[x] = 0;
        }
    };

    enqueue(0, 0);

    for (size_t t = 1; !q.empty(); ++t) {
        const std::vector<size_t> p = std::move(q);

        for (const size_t u : p) {
            for (const size_t v : g[u])
                enqueue(v, t);
        }
    }

    answer(d);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, k;
    std::cin >> n >> m >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    graph_t g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    solve(g, a, k);

    return 0;
}
