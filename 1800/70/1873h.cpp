#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<unsigned>>;

constexpr unsigned oo = ~0u;

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void compute_distances(const graph_t& g, unsigned s, std::vector<unsigned>& d)
{
    const size_t n = g.size();

    d[s] = 0;

    std::vector<unsigned> q = { s };
    for (size_t i = 0; i < q.size(); ++i) {
        const unsigned u = q[i];

        for (const unsigned v : g[u]) {
            if (d[u] + 1 < d[v]) {
                d[v] = d[u] + 1;
                q.push_back(v);
            }
        }
    }
}

unsigned search(const graph_t& g, unsigned u, unsigned p, std::vector<bool>& v)
{
    if (v[u])
        return u;

    v[u] = true;

    for (const unsigned w : g[u]) {
        if (w == p)
            continue;

        const unsigned x = search(g, w, u, v);
        if (x != 0)
            return x;
    }

    return 0;
}

void solve(const graph_t& g, unsigned a, unsigned b)
{
    const size_t n = g.size();

    std::vector<unsigned> da(n, oo), db(n, oo);
    compute_distances(g, a, da);
    compute_distances(g, b, db);

    std::vector<bool> v(n);
    const unsigned x = search(g, b, 0, v);

    answer(db[x] < da[x]);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned a, b;
    std::cin >> a >> b;

    graph_t g(1+n);
    for (size_t i = 0; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    solve(g, a, b);
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
