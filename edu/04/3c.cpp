#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

class SegmentTree {
    struct Node {
        unsigned range_size = 1;
        unsigned count = 0;

        bool inverted = 0;       // pending cumulative update for subnodes

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

    unsigned search(unsigned target)
    {
        return search({ 1, 0, size_ }, target);
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

    unsigned search(const Subtree& subtree, unsigned target)
    {
        if (subtree.range_begin + 1 == subtree.range_end)
            return subtree.range_begin;

        nodes_[subtree.root_index].propagate_updates(nodes_[subtree.root_index<<1|0], nodes_[subtree.root_index<<1|1]);

        const unsigned mid = (subtree.range_begin + subtree.range_end) / 2;
        if (target < nodes_[subtree.root_index<<1|0].count)
            return search({ subtree.root_index<<1|0, subtree.range_begin, mid }, target);

        target -= nodes_[subtree.root_index<<1|0].count;
        return search({ subtree.root_index<<1|1, mid, subtree.range_end }, target);
    }

private:
    const unsigned size_;

    std::vector<Node> nodes_;

}; // class SegmentTree

void solve(const std::vector<unsigned>& as)
{
    const unsigned m = as.size(), n = m / 2;

    std::vector<unsigned> vs(n, m), xs(n);

    SegmentTree st(m);
    for (unsigned i = 0; i < m; ++i) {
        const unsigned a = as[i] - 1;
        if (vs[a] == m) {
            vs[a] = i;
        } else {
            xs[a] = st.query(vs[a], i).count;
            st.update(vs[a], vs[a] + 1);
        }
    }

    for (unsigned i = 0; i < n; ++i)
        std::cout << xs[i] << ' ';
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    std::vector<unsigned> as(2 * n);
    std::cin >> as;

    solve(as);

    return 0;
}
