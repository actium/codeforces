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
    char c;
    int x;
    unsigned l;
};

std::istream& operator >>(std::istream& input, Query& q)
{
    return input >> q.c >> q.x >> q.l;
}

class SegmentTree {
    struct Node {
        unsigned range_size = 1;

        char lower_bound_color = 'W';
        char upper_bound_color = 'W';

        unsigned black_segment_count = 0;
        unsigned black_segment_length = 0;

        char common_color = ' ';

        void update(char color)
        {
            lower_bound_color = color;
            upper_bound_color = color;

            if (color == 'B') {
                black_segment_count = 1;
                black_segment_length = range_size;
            } else {
                black_segment_count = 0;
                black_segment_length = 0;
            }

            common_color = color;
        }

        void propagate_updates(Node& lhs, Node& rhs)
        {
            if (common_color != ' ') {
                lhs.update(common_color);
                rhs.update(common_color);
                common_color = ' ';
            }
        }

        static Node compose(const Node& lhs, const Node& rhs)
        {
            return {
                .range_size = lhs.range_size + rhs.range_size,
                .lower_bound_color = lhs.lower_bound_color,
                .upper_bound_color = rhs.upper_bound_color,
                .black_segment_count = lhs.black_segment_count + rhs.black_segment_count
                                     - (lhs.upper_bound_color == 'B' && rhs.lower_bound_color == 'B'),
                .black_segment_length = lhs.black_segment_length + rhs.black_segment_length,
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

void solve(const std::vector<Query>& qs)
{
    constexpr unsigned k = 500000, n = k + 1 + k;

    SegmentTree st(n);
    for (const Query& q : qs) {
        st.update(q.x + k, q.x + k + q.l, q.c);

        const auto result = st.query(0, n);
        std::cout << result.black_segment_count << ' ' << result.black_segment_length << '\n';
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    std::vector<Query> qs(n);
    std::cin >> qs;

    solve(qs);

    return 0;
}
