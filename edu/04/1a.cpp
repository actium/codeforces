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
            unsigned i;
            unsigned v;
        };
        struct {
            unsigned l;
            unsigned r;
        };
    };
};

std::istream& operator >>(std::istream& input, Query& q)
{
    return input >> q.t >> q.i >> q.v;
}

class SegmentTree {
    struct Node {
        unsigned long long sum = 0;

        void initialize(unsigned value)
        {
            sum = value;
        }

        void update()
        {}

        void propagate_updates(Node& lhs, Node& rhs)
        {}

        static Node compose(const Node& lhs, const Node& rhs)
        {
            return {
                .sum = lhs.sum + rhs.sum,
            };
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

    void set(unsigned index, unsigned value)
    {
        set({ 1, 0, size_ }, index, value);
    }

    template <typename... T>
    void update(unsigned range_begin, unsigned range_end, T&&... arguments)
    {
        update({ 1, 0, size_ }, range_begin, range_end, std::forward<T>(arguments)...);
    }

    Node query(unsigned range_begin, unsigned range_end)
    {
        return query({ 1, 0, size_ }, range_begin, range_end);
    }

private:
    struct Subtree {
        unsigned root_index;
        unsigned range_begin;
        unsigned range_end;
    };

    void set(const Subtree& subtree, unsigned index, unsigned value)
    {
        if (subtree.range_begin + 1 == subtree.range_end) {
            nodes_[subtree.root_index].initialize(value);
            return;
        }

        nodes_[subtree.root_index].propagate_updates(nodes_[subtree.root_index<<1|0], nodes_[subtree.root_index<<1|1]);

        const unsigned mid = (subtree.range_begin + subtree.range_end) / 2;
        if (index < mid) {
            set({ subtree.root_index<<1|0, subtree.range_begin, mid }, index, value);
        } else {
            set({ subtree.root_index<<1|1, mid, subtree.range_end }, index, value);
        }
        nodes_[subtree.root_index] = Node::compose(nodes_[subtree.root_index<<1|0], nodes_[subtree.root_index<<1|1]);
    }

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

    Node query(const Subtree& subtree, unsigned range_begin, unsigned range_end)
    {
        if (range_end <= subtree.range_begin || subtree.range_end <= range_begin)
            return {};

        if (range_begin <= subtree.range_begin && subtree.range_end <= range_end)
            return nodes_[subtree.root_index];

        nodes_[subtree.root_index].propagate_updates(nodes_[subtree.root_index<<1|0], nodes_[subtree.root_index<<1|1]);

        const unsigned mid = (subtree.range_begin + subtree.range_end) / 2;
        return Node::compose(
            query({ subtree.root_index<<1|0, subtree.range_begin, mid }, range_begin, range_end),
            query({ subtree.root_index<<1|1, mid, subtree.range_end }, range_begin, range_end)
        );
    }

private:
    const unsigned size_;

    std::vector<Node> nodes_;

}; // class SegmentTree

void solve(const std::vector<unsigned>& as, const std::vector<Query>& qs)
{
    SegmentTree st(as.begin(), as.end());
    for (const Query& q : qs) {
        if (q.t == 1) {
            st.set(q.i, q.v);
        } else {
            std::cout << st.query(q.l, q.r).sum << '\n';
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m;
    std::cin >> n >> m;

    std::vector<unsigned> as(n);
    std::cin >> as;

    std::vector<Query> qs(m);
    std::cin >> qs;

    solve(as, qs);

    return 0;
}
