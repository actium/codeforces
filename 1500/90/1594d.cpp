#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

struct Graph {
    struct Edge {
        size_t s;
        size_t t;
        char c;
    };

    std::vector<Edge> edges;
    std::vector<std::vector<size_t>> nodes;

    explicit Graph(size_t n)
        : nodes(n)
    {}

    void add_edge(unsigned s, unsigned t, const std::string& c)
    {
        nodes[s-1].push_back(edges.size());
        nodes[t-1].push_back(edges.size());
        edges.push_back({ s-1, t-1, c[0] });
    }

    int count(size_t u, unsigned q, std::vector<unsigned>& s) const
    {
        if (s[u] != 0)
            return s[u] == q ? 0 : -1;

        s[u] = q;

        unsigned k = (q == 1);
        for (const size_t x : nodes[u]) {
            const Edge& e = edges[x];

            const int d = count(u^e.s^e.t, (e.c == 'c') == (q == 1) ? 1 : 2, s);
            if (d == -1)
                return -1;

            k += d;
        }
        return k;
    }
};

void solve(const Graph& g)
{
    const size_t n = g.nodes.size();

    std::vector<int> q(n, -1);

    const auto count = [&](unsigned x) {
        std::vector<unsigned> s(n);
        for (size_t i = 0; i < n; ++i)
            q[i] = std::max(q[i], s[i] == 0 ? g.count(i, x, s) : 0);
    };

    count(1);
    count(2);

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        if (q[i] == -1)
            return no_answer();

        k += q[i];
    }

    answer(k);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    Graph g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned s, t;
        std::cin >> s >> t;

        std::string c;
        std::cin >> c;

        g.add_edge(s, t, c);
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
