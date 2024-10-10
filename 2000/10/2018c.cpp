#include <iostream>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

struct Node {
    size_t parent = 0;
    std::vector<size_t> subnodes;
    size_t subtree_size = 1;
    size_t subtree_height = 0;
};

void prepare(const std::vector<std::vector<size_t>>& g, size_t u, size_t p, std::vector<Node>& tree)
{
    tree[u].parent = p;

    for (const size_t v : g[u]) {
        if (v != p) {
            prepare(g, v, u, tree);

            tree[u].subnodes.push_back(v);
            tree[u].subtree_size += tree[v].subtree_size;
            tree[u].subtree_height = std::max(tree[u].subtree_height, tree[v].subtree_height + 1);
        }
    }
}

void solve(const std::vector<std::vector<size_t>>& g)
{
    const size_t n = g.size();

    std::vector<Node> tree(n);
    prepare(g, 0, 0, tree);

    unsigned c = n;
    {
        std::vector<size_t> q = { 0 };
        std::vector<bool> x(n);
        for (size_t depth = 0, b = 0; depth <= tree[0].subtree_height; ++depth) {
            std::vector<size_t> nq;

            unsigned k = b;
            for (size_t u : q) {
                for (const size_t v : tree[u].subnodes) {
                    nq.push_back(v);
                    k += tree[v].subtree_size;
                }

                for (size_t d = 0; u != 0 && tree[u].subtree_height == d && !x[u]; u = tree[u].parent, ++d) {
                    x[u] = true;
                    ++b;
                }
            }
            c = std::min(c, k);

            std::swap(q, nq);
        }
    }
    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<std::vector<size_t>> g(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v;
        std::cin >> u >> v;

        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
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
