#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Query {
    unsigned t;
    union {
        struct {
            unsigned l;
            unsigned r;
            unsigned v;
        };
        unsigned i;
    };
};

std::istream& operator >>(std::istream& input, Query& q)
{
    input >> q.t;
    return q.t == 1 ? input >> q.l >> q.r >> q.v : input >> q.i;
}

class SegmentTree {
    struct Node {
        unsigned value = 0;

        unsigned common_value = ~0u;       // pending cumulative update for subnodes

        void initialize(unsigned value)
        {
            this->value = value;
        }

        void update(unsigned value)
        {
            this->value = value;
            common_value = value;
        }

        void propagate_updates(Node& lhs, Node& rhs)
        {
            if (common_value != ~0u) {
                lhs.update(common_value);
                rhs.update(common_value);
                common_value = ~0u;
            }
        }

        static Node compose(const Node& lhs, const Node& rhs)
        {
            return {};
        }
    };

public:
    explicit SegmentTree(unsigned size)
        : size_(1 << __builtin_clz(1) - __builtin_clz(size) + 1)
        , nodes_(2 * size_)
    {}

    template <typename Iterator>
    SegmentTree(Iterator begin, Iterator end)
        : SegmentTree(std::distance(begin, end))
    {
        for (unsigned i = size_; begin != end; ++begin)
            nodes_[i++].initialize(*begin);

        for (unsigned i = size_ - 1; i > 0; --i)
            nodes_[i] = Node::compose(nodes_[i<<1|0], nodes_[i<<1|1]);
    }

    template <typename... T>
    void update(unsigned range_begin, unsigned range_end, T&&... arguments)
    {
        update({ 1, 0, size_ }, range_begin, range_end, std::forward<T>(arguments)...);
    }

    Node query(unsigned range_begin, unsigned range_end)
    {
        return query(range_begin, range_end, { 1, 0, size_ });
    }

    Node get(unsigned index)
    {
        return get({ 1, 0, size_ }, index);
    }

private:
    struct Subtree {
        unsigned root_index;
        unsigned range_begin;
        unsigned range_end;
    };

    template <typename... T>
    void update(const Subtree& subtree, unsigned range_begin, unsigned range_end, T&&... arguments)
    {
        if (range_end <= subtree.range_begin || subtree.range_end <= range_begin)
            return;

        if (range_begin <= subtree.range_begin && subtree.range_end <= range_end) {
            nodes_[subtree.root_index].update(std::forward<T>(arguments)...);
            return;
        }

        nodes_[subtree.root_index].propagate_updates(nodes_[subtree.root_index<<1|0], nodes_[subtree.root_index<<1|1]);

        const unsigned mid = (subtree.range_begin + subtree.range_end) / 2;
        update({ subtree.root_index<<1|0, subtree.range_begin, mid }, range_begin, range_end, std::forward<T>(arguments)...);
        update({ subtree.root_index<<1|1, mid, subtree.range_end }, range_begin, range_end, std::forward<T>(arguments)...);
        nodes_[subtree.root_index] = Node::compose(nodes_[subtree.root_index<<1|0], nodes_[subtree.root_index<<1|1]);
    }

    Node query(unsigned range_begin, unsigned range_end, const Subtree& subtree)
    {
        if (range_end <= subtree.range_begin || subtree.range_end <= range_begin)
            return {};

        if (range_begin <= subtree.range_begin && subtree.range_end <= range_end)
            return nodes_[subtree.root_index];

        nodes_[subtree.root_index].propagate_updates(nodes_[subtree.root_index<<1|0], nodes_[subtree.root_index<<1|1]);

        const unsigned mid = (subtree.range_begin + subtree.range_end) / 2;
        return Node::compose(
            query(range_begin, range_end, { subtree.root_index<<1|0, subtree.range_begin, mid }),
            query(range_begin, range_end, { subtree.root_index<<1|1, mid, subtree.range_end })
        );
    }

    Node get(const Subtree& subtree, unsigned index)
    {
        if (subtree.range_begin + 1 == subtree.range_end)
            return nodes_[subtree.root_index];

        nodes_[subtree.root_index].propagate_updates(nodes_[subtree.root_index<<1|0], nodes_[subtree.root_index<<1|1]);

        const unsigned mid = (subtree.range_begin + subtree.range_end) / 2;
        if (index < mid)
            return get({ subtree.root_index<<1|0, subtree.range_begin, mid }, index);

        return get({ subtree.root_index<<1|1, mid, subtree.range_end }, index);
    }

private:
    const unsigned size_;

    std::vector<Node> nodes_;

}; // class SegmentTree

void solve(unsigned n, const std::vector<Query>& qs)
{
    SegmentTree st(n);
    for (const Query& q : qs) {
        if (q.t == 1) {
            st.update(q.l, q.r, q.v);
        } else {
            std::cout << st.get(q.i).value << '\n';
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m;
    std::cin >> n >> m;

    std::vector<Query> qs(m);
    std::cin >> qs;

    solve(n, qs);

    return 0;
}
