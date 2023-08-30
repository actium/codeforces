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

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

std::pair<bool, unsigned> check(const graph_t& g, const std::vector<unsigned>& p, const std::vector<int>& h, size_t u, size_t r)
{
    unsigned k = 0, v = p[u];
    for (const size_t x : g[u]) {
        if (x == r)
            continue;

        const std::pair<bool, unsigned> status = check(g, p, h, x, u);
        if (!status.first)
            return status;

        const unsigned d = status.second - abs(h[x]);
        if (d % 2 != 0)
            return std::make_pair(false, 0);

        k += -std::min(h[x], 0) + d / 2;
        v += status.second;
    }

    const unsigned d = (h[u] < 0 ? v + h[u] : v - h[u]);
    if (d % 2 != 0)
        return std::make_pair(false, 0);

    const unsigned q = -std::min(h[u], 0) + d / 2;
    return std::make_pair(q <= k + p[u], v);
}

void solve(graph_t& g, const std::vector<unsigned>& p, const std::vector<int>& h)
{
    answer(check(g, p, h, 0, 0).first);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<unsigned> p(n);
    std::cin >> p;

    std::vector<int> h(n);
    std::cin >> h;

    graph_t g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned x, y;
        std::cin >> x >> y;

        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }

    solve(g, p, h);
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
