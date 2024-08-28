#include <iostream>
#include <vector>

class Graph {
    struct Edge {
        size_t target;
        unsigned subtree_size;
    };

public:
    explicit Graph(size_t vertex_count)
        : nodes_(vertex_count)
    {}

    void connect(size_t s, size_t t)
    {
        nodes_[s].push_back({ t, ~0u });
    }

    void explore()
    {
        const size_t vertex_count = nodes_.size();

        explore(0, 0);

        for (size_t i = 0; i < vertex_count; ++i) {
            for (Edge& e : nodes_[i]) {
                if (e.subtree_size == ~0u)
                    e.subtree_size = explore(e.target, i);
            }
        }
    }

    std::vector<size_t> centroids() const
    {
        const size_t vertex_count = nodes_.size();

        std::vector<size_t> centroids;
        {
            unsigned k = ~0u;
            for (size_t i = 0; i < vertex_count; ++i) {
                unsigned c = 0;
                for (const Edge& e : nodes_[i])
                    c = std::max(c, e.subtree_size);

                if (c < k) {
                    k = c;
                    centroids.clear();
                }

                if (c == k)
                    centroids.push_back(i);
            }
        }
        return centroids;
    }

    std::vector<size_t> adjacents(size_t v) const
    {
        std::vector<size_t> s;
        for (const Edge& e : nodes_[v])
            s.push_back(e.target);

        return s;
    }

private:
    unsigned explore(size_t u, size_t p)
    {
        unsigned k = 1;
        for (Edge& e : nodes_[u]) {
            if (e.target == p)
                continue;

            if (e.subtree_size == ~0u)
                e.subtree_size = explore(e.target, u);

            k += e.subtree_size;
        }
        return k;
    }

private:
    std::vector<std::vector<Edge>> nodes_;

}; // class Graph

void answer(const std::pair<size_t, size_t>& x, const std::pair<size_t, size_t>& y)
{
    std::cout << 1+x.first << ' ' << 1+x.second << '\n';
    std::cout << 1+y.first << ' ' << 1+y.second << '\n';
}

void solve(Graph& g)
{
    g.explore();

    const std::vector<size_t> c = g.centroids(), s = g.adjacents(c.front());
    answer({ c.front(), s[s[0]==c.back()] }, { c.back(), s[s[0]==c.back()] });
}

void test_case()
{
    size_t n;
    std::cin >> n;

    Graph g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g.connect(u-1, v-1);
        g.connect(v-1, u-1);
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
