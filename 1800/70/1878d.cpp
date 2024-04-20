#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

class Treap {
    struct Node {
        unsigned priority = rand();
        unsigned size = 1;
        unsigned subnodes[2] = {};

        char value;

        bool reversed = false;
    };

public:
    explicit Treap(const std::string& data)
    {
        const size_t size = data.length();

        nodes_.resize(1 + size);
        for (size_t i = 0; i < size; ++i) {
            nodes_[1+i].value = data[i];
            root_ = merge(root_, 1 + i);
        }
    }

    void reverse(unsigned li, unsigned ri)
    {
        auto splice_s = split(root_, ri);
        auto splice_p = split(splice_s.first, li);

        if (splice_p.second != 0)
            nodes_[splice_p.second].reversed = !nodes_[splice_p.second].reversed;

        root_ = merge(splice_p.first, splice_p.second);
        root_ = merge(root_, splice_s.second);
    }

    std::string finalize()
    {
        std::string data;
        output(root_, data);
        return data;
    }

private:
    unsigned size(unsigned node_id) const
    {
        return node_id != 0 ? nodes_[node_id].size : 0;
    }

    std::pair<unsigned, unsigned> split(unsigned root, unsigned position)
    {
        std::pair<unsigned, unsigned> nodes = {};
        if (root == 0)
            return nodes;

        push(root);

        const unsigned partial_size = size(nodes_[root].subnodes[0]);
        if (partial_size >= position) {
            nodes = split(nodes_[root].subnodes[0], position);
            nodes_[root].subnodes[0] = nodes.second;
            nodes.second = root;
        } else {
            nodes = split(nodes_[root].subnodes[1], position - partial_size - 1);
            nodes_[root].subnodes[1] = nodes.first;
            nodes.first = root;
        }
        nodes_[root].size = size(nodes_[root].subnodes[0]) + size(nodes_[root].subnodes[1]) + 1;
        return nodes;
    }

    unsigned merge(unsigned lhs, unsigned rhs)
    {
        push(lhs);
        push(rhs);

        if (lhs == 0)
            return rhs;

        if (rhs == 0)
            return lhs;

        unsigned node = 0;
        if (nodes_[lhs].priority > nodes_[rhs].priority) {
            nodes_[lhs].subnodes[1] = merge(nodes_[lhs].subnodes[1], rhs);
            node = lhs;
        } else {
            nodes_[rhs].subnodes[0] = merge(lhs, nodes_[rhs].subnodes[0]);
            node = rhs;
        }
        nodes_[node].size = size(nodes_[node].subnodes[0]) + size(nodes_[node].subnodes[1]) + 1;
        return node;
    }

    void push(unsigned node_id)
    {
        if (node_id == 0 || !nodes_[node_id].reversed)
            return;

        unsigned& lhs = nodes_[node_id].subnodes[0];
        unsigned& rhs = nodes_[node_id].subnodes[1];

        if (lhs != 0)
            nodes_[lhs].reversed = !nodes_[lhs].reversed;

        if (rhs != 0)
            nodes_[rhs].reversed = !nodes_[rhs].reversed;

        std::swap(lhs, rhs);

        nodes_[node_id].reversed = false;
    }

    void output(unsigned node_id, std::string& buffer)
    {
        if (node_id == 0)
            return;

        push(node_id);

        output(nodes_[node_id].subnodes[0], buffer);
        buffer.push_back(nodes_[node_id].value);
        output(nodes_[node_id].subnodes[1], buffer);
    }

private:
    std::vector<Node> nodes_;

    unsigned root_ = 0;

}; // class Treap

void solve(const std::string& s, const std::vector<unsigned>& l, const std::vector<unsigned>& r, const std::vector<unsigned>& x)
{
    Treap t(s);
    for (const unsigned q : x) {
        const size_t i = std::upper_bound(l.begin(), l.end(), q) - l.begin() - 1;

        const unsigned a = std::min(q, r[i] + l[i] - q), b = std::max(q, r[i] + l[i] - q);
        t.reverse(a-1, b);
    }

    answer(t.finalize());
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    std::vector<unsigned> l(k), r(k);
    std::cin >> l >> r;

    size_t q;
    std::cin >> q;

    std::vector<unsigned> x(q);
    std::cin >> x;

    solve(s, l, r, x);
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
