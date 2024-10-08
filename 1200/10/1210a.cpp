#include <algorithm>
#include <iostream>
#include <vector>

using graph_t = std::vector<std::vector<size_t>>;

const std::vector<std::pair<unsigned, unsigned>> s = {
    { 1, 1 }, { 1, 2 }, { 1, 3 }, { 1, 4 }, { 1, 5 }, { 1, 6 },
    { 2, 2 }, { 2, 3 }, { 2, 4 }, { 2, 5 }, { 2, 6 },
    { 3, 3 }, { 3, 4 }, { 3, 5 }, { 3, 6 },
    { 4, 4 }, { 4, 5 }, { 4, 6 },
    { 5, 5 }, { 5, 6 },
    { 6, 6 },
};

size_t index(unsigned u, unsigned v)
{
    const std::pair<unsigned, unsigned> r = std::minmax(u, v);

    return std::lower_bound(s.begin(), s.end(), r) - s.begin();
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

class Graph {
    struct Edge {
        size_t u;
        size_t v;
        unsigned c;
    };

public:
    explicit Graph(size_t vertex_count)
        : nodes_(vertex_count)
    {}

    size_t size() const
    {
        return nodes_.size();
    }

    void add_edge(unsigned u, unsigned v)
    {
        nodes_[u-1].push_back(edges_.size());
        nodes_[v-1].push_back(edges_.size());
        edges_.push_back({ u-1, v-1, 0 });
    }

    unsigned search(const std::vector<unsigned>& d)
    {
        const size_t n = nodes_.size();

        std::vector<bool> v(n);
        for (size_t i = 0, x = 0; i < n; ++i)
            traverse(d, i, v, x);

        unsigned k = 0;
        for (Edge& e : edges_) {
            k += e.c;
            e.c = 0;
        }
        return k;
    }

private:
    void traverse(const std::vector<unsigned>& d, size_t u, std::vector<bool>& v, size_t& x)
    {
        if (v[u])
            return;

        v[u] = true;

        for (const size_t i : nodes_[u]) {
            Edge& e = edges_[i];
            if (e.c == 0) {
                const size_t p = index(d[e.u], d[e.v]);
                if ((x & 1 << p) == 0) {
                    x |= 1 << p;
                    e.c = 1;
                }
            }

            traverse(d, u ^ e.u ^ e.v, v, x);
        }
    }

private:
    std::vector<std::vector<size_t>> nodes_;
    std::vector<Edge> edges_;

}; // class Graph

bool fill(std::vector<unsigned>& d, unsigned x)
{
    const size_t n = d.size();

    for (size_t j = 0; j < n; ++j) {
        d[j] = (x >> 3 * j) & 0x7;
        if (d[j] == 0 || d[j] == 7)
            return false;
    }
    return true;
}

void solve(Graph& g)
{
    const size_t n = g.size(), b = 1 << 3 * n;

    unsigned k = 0;
    for (unsigned i = 1; i < b; ++i) {
        std::vector<unsigned> d(n);
        if (fill(d, i))
            k = std::max(k, g.search(d));
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    Graph g(n);
    for (size_t i = 0; i < m; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g.add_edge(u, v);
    }

    solve(g);

    return 0;
}
