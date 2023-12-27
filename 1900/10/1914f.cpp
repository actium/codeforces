#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Node {
    std::vector<Node*> subnodes;
    unsigned subtree_size = 1;
};

void compute_subtree_sizes(Node* node)
{
    for (Node* subnode : node->subnodes) {
        compute_subtree_sizes(subnode);
        node->subtree_size += subnode->subtree_size;
    }
}

unsigned count(const Node* node)
{
    if (!node->subnodes.empty()) {
        size_t x = 0;
        for (size_t i = 1; i < node->subnodes.size(); ++i) {
            if (node->subnodes[i]->subtree_size > node->subnodes[x]->subtree_size)
                x = i;
        }

        if (node->subnodes[x]->subtree_size * 2 >= node->subtree_size) {
            const unsigned k = count(node->subnodes[x]);
            return k + std::min((node->subtree_size - 1 - 2 * k) / 2, node->subtree_size - 1 - node->subnodes[x]->subtree_size);
        }
    }
    return (node->subtree_size - 1) / 2;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size() + 1;

    std::vector<Node> nodes(n);
    for (size_t i = 1; i < n; ++i) {
        Node* parent = &nodes[p[i-1]-1];
        parent->subnodes.push_back(&nodes[i]);
    }

    compute_subtree_sizes(&nodes[0]);

    answer(count(&nodes[0]));
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n-1);
    std::cin >> p;

    solve(p);
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
