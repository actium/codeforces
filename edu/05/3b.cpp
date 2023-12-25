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
        };
        unsigned k;
    };
};

std::istream& operator >>(std::istream& input, Query& q)
{
    input >> q.t;
    return q.t == 1 ? input >> q.l >> q.r : input >> q.k;
}

class SegmentTree {
    struct Node {
        unsigned range_size = 1;
        unsigned count = 0;

        bool inverted = false;      // pending cumulative update for subnodes

        void initialize(unsigned value)
        {
            count = value;
        }

        void update()
        {
            count = range_size - count;
            inverted = !inverted;
        }

        void propagate_updates(Node& lhs, Node& rhs)
        {
            if (inverted) {
                lhs.update();
                rhs.update();
                inverted = false;
            }
        }

        static Node compose(const Node& lhs, const Node& rhs)
        {
            return {
                .range_size = lhs.range_size + rhs.range_size,
                .count = lhs.count + rhs.count,
            };
        }
    };

public:
    explicit SegmentTree(unsigned size)
        : size_(1 << __builtin_clz(1) - __builtin_clz(size) + 1)
        , nodes_(2 * size_)
    {
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

    unsigned search(unsigned rank)
    {
        return search({ 1, 0, size_ }, rank);
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

    unsigned search(const Subtree& subtree, unsigned rank)
    {
        if (subtree.range_begin + 1 == subtree.range_end)
            return subtree.range_begin;

        nodes_[subtree.root_index].propagate_updates(nodes_[subtree.root_index<<1|0], nodes_[subtree.root_index<<1|1]);

        const unsigned mid = (subtree.range_begin + subtree.range_end) / 2;
        if (rank < nodes_[subtree.root_index<<1|0].count)
            return search({ subtree.root_index<<1|0, subtree.range_begin, mid }, rank);

        rank -= nodes_[subtree.root_index<<1|0].count;
        return search({ subtree.root_index<<1|1, mid, subtree.range_end }, rank);
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
            st.update(q.l, q.r);
        } else {
            std::cout << st.search(q.k) << '\n';
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
