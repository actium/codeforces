#include <iostream>
#include <queue>
#include <vector>

using integer = unsigned long long;

constexpr integer oo = ~integer(0) >> 1;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

struct Edge {
    size_t v;
    integer w;
};

using graph_t = std::vector<std::vector<Edge>>;

struct State {
    size_t u;
    integer t;
    unsigned s;
};

bool operator <(const State& lhs, const State& rhs)
{
    if (lhs.t != rhs.t)
        return lhs.t > rhs.t;

    return lhs.s != rhs.s ? lhs.s > rhs.s : lhs.u < rhs.u;
}

void solve(const graph_t& g, const std::vector<unsigned>& s)
{
    const size_t n = g.size();

    std::vector<std::vector<integer>> distances(n, std::vector<integer>(1001, oo));
    distances[0][s[0]] = 0;

    std::priority_queue<State> q;
    q.push({ 0, 0, s[0] });
    while (q.top().u != n - 1) {
        const State p = q.top();
        q.pop();

        if (p.t != distances[p.u][p.s])
            continue;

        const unsigned v = std::min(p.s, s[p.u]);
        for (const Edge& e : g[p.u]) {
            if (distances[p.u][p.s] + v * e.w < distances[e.v][v]) {
                distances[e.v][v] = distances[p.u][p.s] + v * e.w;
                q.push({ e.v, distances[e.v][v], v });
            }
        }
    }

    answer(q.top().t);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    graph_t g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned u, v, w;
        std::cin >> u >> v >> w;

        g[u-1].push_back({v-1, w});
        g[v-1].push_back({u-1, w});
    }

    std::vector<unsigned> s(n);
    std::cin >> s;

    solve(g, s);
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
