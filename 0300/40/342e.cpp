#include <array>
#include <iostream>
#include <vector>

constexpr unsigned oo = ~0u >> 1, K = 17;

class Tree {
public:
    explicit Tree(size_t vertex_count)
        : vertex_count_(vertex_count)
        , adjacents_(vertex_count)
        , depths_(vertex_count)
        , jumps_(vertex_count)
    {}

    void add_edge(unsigned u, unsigned v)
    {
        adjacents_[u].push_back(v);
        adjacents_[v].push_back(u);
    }

    std::vector<unsigned> decompose(unsigned root)
    {
        explore(root, root, 0);

        std::vector<unsigned> parents(vertex_count_, oo);
        {
            std::vector<bool> visited(vertex_count_);
            decompose(root, oo, vertex_count_, parents, visited);
        }
        return parents;
    }

    unsigned compute_distance(unsigned u, unsigned v) const
    {
        return depths_[u] + depths_[v] - 2 * depths_[lca(u, v)];
    }

private:
    void explore(unsigned u, unsigned p, unsigned d)
    {
        depths_[u] = d;
        jumps_[u][0] = p;
        for (unsigned i = 1; i < K; ++i)
            jumps_[u][i] = jumps_[jumps_[u][i-1]][i-1];

        for (const unsigned v : adjacents_[u]) {
            if (v != p)
                explore(v, u, d + 1);
        }
    }

    void decompose(unsigned u, unsigned p, size_t ub, std::vector<unsigned>& parents, std::vector<bool>& visited) const
    {
        unsigned center = oo;
        search(visited, u, oo, ub, center);

        parents[center] = p;
        visited[center] = true;

        for (const unsigned v : adjacents_[center]) {
            if (!visited[v])
                decompose(v, center, ub / 2, parents, visited);
        }
    }

    unsigned search(const std::vector<bool>& visited, unsigned u, unsigned p, size_t ub, unsigned& center) const
    {
        unsigned size = 1;
        for (const unsigned v : adjacents_[u]) {
            if (v != p && !visited[v])
                size += search(visited, v, u, ub, center);
        }

        if (center == oo && (p == oo || 2 * size >= ub))
            center = u;

        return size;
    }

    unsigned lca(unsigned u, unsigned v) const
    {
        if (depths_[v] < depths_[u])
            std::swap(u, v);

        for (unsigned i = K; i-- != 0; ) {
            if (depths_[jumps_[v][i]] >= depths_[u])
                v = jumps_[v][i];
        }

        if (v == u)
            return v;

        for (unsigned i = K; i-- != 0; ) {
            if (jumps_[v][i] != jumps_[u][i]) {
                v = jumps_[v][i];
                u = jumps_[u][i];
            }
        }
        return jumps_[v][0];
    }

private:
    const size_t vertex_count_;

    std::vector<std::vector<unsigned>> adjacents_;

    std::vector<unsigned> depths_;
    std::vector<std::array<unsigned, K>> jumps_;

}; // class Tree

struct Query {
    unsigned t;
    unsigned v;
};

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(Tree& tree, const std::vector<Query>& queries)
{
    const std::vector<unsigned> parents = tree.decompose(0);

    std::vector<unsigned> proximates(parents.size(), oo);

    const auto paint = [&](unsigned v) {
        for (unsigned c = v; c != oo; c = parents[c])
            proximates[c] = std::min(proximates[c], tree.compute_distance(c, v));
    };

    paint(0);

    const auto query = [&](unsigned v) {
        unsigned d = oo;
        for (unsigned c = v; c != oo; c = parents[c])
            d = std::min(d, tree.compute_distance(v, c) + proximates[c]);

        return d;
    };

    for (const auto& [t, v] : queries)
        t == 1 ? paint(v-1) : answer(query(v-1));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    Tree tree(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        tree.add_edge(u-1, v-1);
    }

    std::vector<Query> queries(m);
    for (size_t i = 0; i < m; ++i)
        std::cin >> queries[i].t >> queries[i].v;

    solve(tree, queries);

    return 0;
}
