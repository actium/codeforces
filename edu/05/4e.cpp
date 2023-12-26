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
    unsigned h;
};

std::istream& operator >>(std::istream& input, Query& q)
{
    return input >> q.t >> q.l >> q.r >> q.h;
}

class SegmentTree {
    struct Node {
        unsigned height = 0;

        unsigned common_min_height = 0;
        unsigned common_max_height = ~0u;

        void update(unsigned t, unsigned h)
        {
            if (t == 1) {
                height = std::max(height, h);
                common_min_height = std::max(common_min_height, h);
                common_max_height = std::max(common_max_height, h);
            } else {
                height = std::min(height, h);
                common_min_height = std::min(common_min_height, h);
                common_max_height = std::min(common_max_height, h);
            }
        }

        void propagate_updates(Node& lhs, Node& rhs)
        {
            if (common_min_height != 0) {
                lhs.update(1, common_min_height);
                rhs.update(1, common_min_height);
                common_min_height = 0;
            }
            if (common_max_height != ~0u) {
                lhs.update(2, common_max_height);
                rhs.update(2, common_max_height);
                common_max_height = ~0u;
            }
        }

        static Node compose(const Node& lhs, const Node& rhs)
        {
            return {
                .height = std::max(lhs.height, rhs.height),
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

void solve(unsigned n, const std::vector<Query>& qs)
{
    SegmentTree st(n);
    for (const Query& q : qs)
        st.update(q.l, q.r + 1, q.t, q.h);

    for (unsigned i = 0; i < n; ++i)
        std::cout << st.query(i, i + 1).height << '\n';
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, k;
    std::cin >> n >> k;

    std::vector<Query> qs(k);
    std::cin >> qs;

    solve(n, qs);

    return 0;
}
