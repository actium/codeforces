#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

constexpr unsigned oo = ~0u;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void explore(const graph_t& g, size_t u, std::vector<bool>& v, std::vector<size_t>& q)
{
    v[u] = true;

    for (const size_t x : g[u]) {
        if (!v[x])
            explore(g, x, v, q);
    }

    q.push_back(u);
}

void paint(const graph_t& g, size_t u, unsigned k, std::vector<unsigned>& c)
{
    c[u] = k;

    for (const size_t x : g[u]) {
        if (c[x] == oo)
            paint(g, x, k, c);
    }
}

void solve(const graph_t& g, const graph_t& h)
{
    const size_t n = g.size();

    std::vector<size_t> q;
    {
        std::vector<bool> v(n);
        for (size_t i = 0; i < n; ++i) {
            if (!v[i])
                explore(g, i, v, q);
        }
    }

    std::vector<unsigned> c(n, oo);
    {
        unsigned k = 0;
        for (auto it = q.rbegin(); it != q.rend(); ++it) {
            if (c[*it] == oo)
                paint(h, *it, k++, c);
        }
    }

    for (size_t i = 0; i < n; i += 2) {
        if (c[i] == c[i+1])
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a[3];
    for (size_t i = 0; i < 3; ++i) {
        a[i].resize(n);
        std::cin >> a[i];
    }

    graph_t g(2 * n), h(2 * n);

    const auto index = [](int x) {
        return x < 0 ? -x * 2 - 1 : x * 2 - 2;
    };

    const auto add_edges = [&](int u, int v) {
        g[index(-u)].push_back(index(v));
        g[index(-v)].push_back(index(u));

        h[index(v)].push_back(index(-u));
        h[index(u)].push_back(index(-v));
    };

    for (size_t i = 0; i < n; ++i) {
        add_edges(a[0][i], a[1][i]);
        add_edges(a[1][i], a[2][i]);
        add_edges(a[2][i], a[0][i]);
    }

    solve(g, h);
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
