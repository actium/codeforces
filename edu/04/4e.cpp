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
            unsigned h;
        };
        struct {
            unsigned l;
            unsigned r;
            unsigned p;
        };
    };
};

std::istream& operator >>(std::istream& input, Query& q)
{
    input >> q.t;
    return q.t == 1 ? input >> q.i >> q.h : input >> q.l >> q.r >> q.p;
}

class SegmentTree {
    struct Node {
        unsigned min = 1000000000;

        void initialize(unsigned value)
        {
            min = value;
        }

        void update()
        {}

        void propagate_updates(Node& lhs, Node& rhs)
        {}

        static Node compose(const Node& lhs, const Node& rhs)
        {
            return {
                .min = std::min(lhs.min, rhs.min),
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

    unsigned reset(unsigned range_begin, unsigned range_end, unsigned height)
    {
        return reset({ 1, 0, size_ }, range_begin, range_end, height);
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

    unsigned reset(const Subtree& subtree, unsigned range_begin, unsigned range_end, unsigned power)
    {
        if (range_end <= subtree.range_begin || subtree.range_end <= range_begin)
            return 0;

        if (nodes_[subtree.root_index].min > power)
            return 0;

        if (subtree.range_begin + 1 == subtree.range_end) {
            nodes_[subtree.root_index] = {};
            return 1;
        }

        nodes_[subtree.root_index].propagate_updates(nodes_[subtree.root_index<<1|0], nodes_[subtree.root_index<<1|1]);

        const unsigned mid = (subtree.range_begin + subtree.range_end) / 2;

        const unsigned count = reset({ subtree.root_index<<1|0, subtree.range_begin, mid }, range_begin, range_end, power)
                             + reset({ subtree.root_index<<1|1, mid, subtree.range_end }, range_begin, range_end, power);
        nodes_[subtree.root_index] = Node::compose(nodes_[subtree.root_index<<1|0], nodes_[subtree.root_index<<1|1]);
        return count;
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
            st.set(q.i, q.h);
        } else {
            std::cout << st.reset(q.l, q.r, q.p) << '\n';
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
