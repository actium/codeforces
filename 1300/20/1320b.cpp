#include <iostream>
#include <set>
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

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void compute_distances(const graph_t& g, size_t s, std::vector<unsigned>& d)
{
    std::vector<size_t> q;

    const auto enqueue = [&](size_t x, unsigned w) {
        if (w < d[x]) {
            d[x] = w;
            q.push_back(x);
        }
    };

    enqueue(s, 0);
    for (size_t i = 0; i < q.size(); ++i) {
        const size_t p = q[i];

        for (const size_t x : g[p])
            enqueue(x, d[p] + 1);
    }
}

void solve(const graph_t& g, const graph_t& h, const std::vector<unsigned>& p)
{
    const size_t n = g.size(), k = p.size();

    std::vector<unsigned> d(n, oo);
    compute_distances(h, p.back()-1, d);

    unsigned lc = 0, uc = 0;
    for (size_t i = 1; i < k; ++i) {
        const size_t s = p[i-1] - 1, t = p[i] - 1;

        std::set<size_t> c;
        for (const size_t x : g[s]) {
            if (d[x] == d[s] - 1)
                c.insert(x);
        }

        lc += (c.count(t) == 0);
        uc += (c.count(t) == 0 || c.size() > 1);
    }

    answer(lc, uc);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    graph_t g(n), h(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        h[v-1].push_back(u-1);
    }

    size_t k;
    std::cin >> k;

    std::vector<unsigned> p(k);
    std::cin >> p;

    solve(g, h, p);

    return 0;
}
