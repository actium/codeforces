#include <iostream>
#include <vector>

using integer = unsigned long long;

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

void no_answer()
{
    std::cout << -1 << '\n';
}

struct Node {
    size_t index = 0;
    unsigned value = 0;

    Node* parent = nullptr;
    std::vector<Node*> subnodes;
};

bool fill(Node* root, std::vector<int>& s)
{
    if (s[root->index] != -1) {
        root->value = s[root->index] - (root->parent != nullptr ? s[root->parent->index] : 0);
    } else {
        unsigned b = ~0u;
        for (const Node* node : root->subnodes)
            b = std::min<unsigned>(b, s[node->index]);

        if (b < s[root->parent->index])
            return false;

        if (b != ~0u)
            root->value = b - s[root->parent->index];

        s[root->index] = s[root->parent->index] + root->value;
    }

    for (Node* node : root->subnodes) {
        if (!fill(node, s))
            return false;
    }

    return true;
}

void solve(const std::vector<unsigned>& p, std::vector<int>& s)
{
    const size_t n = s.size();

    std::vector<Node> nodes(n);
    for (size_t i = 1; i < n; ++i) {
        const size_t parent = p[i-1] - 1;
        nodes[parent].subnodes.push_back(&nodes[i]);
        nodes[i].index = i;
        nodes[i].parent = &nodes[parent];
    }

    if (!fill(&nodes[0], s))
        return no_answer();

    integer t = 0;
    for (size_t i = 0; i < n; ++i)
        t += nodes[i].value;

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n-1);
    std::cin >> p;

    std::vector<int> s(n);
    std::cin >> s;

    solve(p, s);

    return 0;
}
