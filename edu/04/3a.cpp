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
        unsigned long long sum = 0;

        unsigned long long common_delta = 0;       // pending cumulative update for subnodes

        void initialize(unsigned value)
        {
            sum = value;
        }

        void update(unsigned delta)
        {
            sum += delta * range_size;
            common_delta += delta;
        }

        void propagate_updates(Node& lhs, Node& rhs)
        {
            lhs.update(common_delta);
            rhs.update(common_delta);
            common_delta = 0;
        }

        static Node compose(const Node& lhs, const Node& rhs)
        {
            return {
                .range_size = lhs.range_size + rhs.range_size,
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

    template <typename... T>
    void update(unsigned range_begin, unsigned range_end, T&&... arguments)
    {
        update({ 1, 0, size_ }, range_begin, range_end, std::forward<T>(arguments)...);
    }

    Node query(unsigned range_begin, unsigned range_end)
    {
        return query(range_begin, range_end, { 1, 0, size_ });
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

private:
    const unsigned size_;

    std::vector<Node> nodes_;

}; // class SegmentTree

void solve(const std::vector<unsigned>& ps)
{
    const unsigned n = ps.size();

    SegmentTree st(n);
    for (const unsigned p : ps) {
        std::cout << st.query(p, n).sum << ' ';
        st.update(p - 1, p, 1);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    std::vector<unsigned> ps(n);
    std::cin >> ps;

    solve(ps);

    return 0;
}
