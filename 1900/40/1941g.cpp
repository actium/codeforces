#include <iostream>
#include <map>
#include <set>
#include <vector>

constexpr unsigned oo = ~0u;

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

struct Edge {
    unsigned u;
    unsigned v;
    unsigned c;
};

std::istream& operator >>(std::istream& input, Edge& e)
{
    return input >> e.u >> e.v >> e.c;
}

void solve(size_t n, std::vector<Edge>& edges, size_t s, size_t t)
{
    std::map<unsigned, size_t> c;
    for (Edge& e : edges) {
        --e.u;
        --e.v;
        c.emplace(e.c, n + c.size());
        e.c = c[e.c];
    }

    n += c.size();

    std::vector<std::vector<std::pair<size_t, unsigned>>> g(n);
    for (const Edge& e : edges) {
        g[e.u].emplace_back(e.c, 1);
        g[e.c].emplace_back(e.u, 0);

        g[e.v].emplace_back(e.c, 1);
        g[e.c].emplace_back(e.v, 0);
    }

    std::vector<unsigned> d(n, oo);
    std::set<std::pair<unsigned, size_t>> q;

    const auto enqueue = [&](size_t u, unsigned w) {
        if (w >= d[u])
            return;

        if (d[u] != oo)
            q.erase(std::make_pair(d[u], u));

        d[u] = w;
        q.emplace(w, u);
    };

    enqueue(s, 0);
    while (!q.empty() && q.begin()->second != t) {
        const auto x = *q.begin();
        q.erase(q.begin());

        for (const auto& v : g[x.second])
            enqueue(v.first, x.first + v.second);
    }

    answer(d[t]);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::vector<Edge> edges(m);
    std::cin >> edges;

    unsigned b, e;
    std::cin >> b >> e;

    solve(n, edges, b-1, e-1);
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
