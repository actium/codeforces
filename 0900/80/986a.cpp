#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

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

void solve(const graph_t& g, const std::vector<unsigned>& a, size_t k, size_t s)
{
    const size_t n = g.size();

    std::vector<std::vector<unsigned>> d(n, std::vector<unsigned>(k, ~0u));
    {
        std::queue<size_t> q[100];

        const auto enqueue = [&](size_t u, size_t v, unsigned w) {
            if (w < d[u][v]) {
                d[u][v] = w;
                q[v].push(u);
            }
        };

        for (size_t i = 0; i < n; ++i)
            enqueue(i, a[i] - 1, 0);

        for (size_t i = 0; i < k; ++i) {
            while (!q[i].empty()) {
                const size_t p = q[i].front();
                q[i].pop();

                for (const size_t v : g[p])
                    enqueue(v, i, d[p][i] + 1);
            }
        }
    }

    std::vector<unsigned> c(n);
    for (size_t i = 0; i < n; ++i) {
        if (s < k)
            std::nth_element(d[i].begin(), d[i].begin() + s, d[i].end());

        for (size_t j = 0; j < s; ++j)
            c[i] += d[i][j];
    }

    answer(c);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m, k, s;
    std::cin >> n >> m >> k >> s;

    std::vector<unsigned> a(n);
    std::cin >> a;

    graph_t g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    solve(g, a, k, s);

    return 0;
}
