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
    unsigned l;
    unsigned r;
    int d;
};

std::istream& operator >>(std::istream& input, Query& q)
{
    input >> q.t;
    return q.t == 1 ? input >> q.l >> q.r >> q.d : input >> q.l >> q.r;
}

class SegmentTree {
    struct Node {
        long long range_size = 0;
        long long sum = 0;
        long long weighted_sum = 0;

        int common_delta = 0;       // pending cumulative update for subnodes

        void initialize(int value)
        {
            range_size = 1;
            sum = value;
            weighted_sum = value;
        }

        void update(int delta)
        {
            sum += range_size * delta;
            weighted_sum += range_size * (range_size + 1) * delta / 2;

            common_delta += delta;
        }

        void propagate_updates(Node& lhs, Node& rhs)
        {
            if (common_delta != 0) {
                lhs.update(common_delta);
                rhs.update(common_delta);
                common_delta = 0;
            }
        }

        static Node compose(const Node& lhs, const Node& rhs)
        {
            const Node result = {
                .range_size = lhs.range_size + rhs.range_size,
                .sum = lhs.sum + rhs.sum,
                .weighted_sum = lhs.weighted_sum + lhs.range_size * rhs.sum + rhs.weighted_sum,
            };
            return result;
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

void solve(const std::vector<int>& as, const std::vector<Query>& qs)
{
    SegmentTree st(as.begin(), as.end());
    for (const Query& q : qs) {
        if (q.t == 1) {
            st.update(q.l-1, q.r, q.d);
        } else {
            std::cout << st.query(q.l-1, q.r).weighted_sum << '\n';
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m;
    std::cin >> n >> m;

    std::vector<int> as(n);
    std::cin >> as;

    std::vector<Query> qs(m);
    std::cin >> qs;

    solve(as, qs);

    return 0;
}
