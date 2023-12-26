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
            unsigned a;
            unsigned d;
        };
        unsigned i;
    };
};

std::istream& operator >>(std::istream& input, Query& q)
{
    input >> q.t;
    return q.t == 1 ? input >> q.l >> q.r >> q.a >> q.d : input >> q.i;
}

class SegmentTree {
    struct Node {
        unsigned range_size = 1;
        unsigned long long value = 0;

        unsigned long long common_first_term = 0;
        unsigned long long common_delta = 0;

        void update(unsigned long long first_term, unsigned long long delta)
        {
            value += first_term;
            common_first_term += first_term;
            common_delta += delta;
        }

        void propagate_updates(Node& lhs, Node& rhs)
        {
            if (common_delta != 0) {
                lhs.update(common_first_term, common_delta);
                rhs.update(common_first_term + common_delta * lhs.range_size, common_delta);
                common_first_term = 0;
                common_delta = 0;
            }
        }

        static Node compose(const Node& lhs, const Node& rhs)
        {
            return {
                .range_size = lhs.range_size + rhs.range_size,
                .value = lhs.value + rhs.value,
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

    void update(unsigned range_begin, unsigned range_end, unsigned a, unsigned d)
    {
        update({ 1, 0, size_ }, range_begin, range_end, a, d);
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

    void update(const Subtree& subtree, unsigned range_begin, unsigned range_end, unsigned a, unsigned d)
    {
        if (range_end <= subtree.range_begin || subtree.range_end <= range_begin)
            return;

        if (range_begin <= subtree.range_begin && subtree.range_end <= range_end) {
            nodes_[subtree.root_index].update(a + 1ull * d * (subtree.range_begin - range_begin), d);
            return;
        }

        nodes_[subtree.root_index].propagate_updates(nodes_[subtree.root_index<<1|0], nodes_[subtree.root_index<<1|1]);

        const unsigned mid = (subtree.range_begin + subtree.range_end) / 2;
        update({ subtree.root_index<<1|0, subtree.range_begin, mid }, range_begin, range_end, a, d);
        update({ subtree.root_index<<1|1, mid, subtree.range_end }, range_begin, range_end, a, d);
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
    for (const Query& q : qs) {
        if (q.t == 1) {
            st.update(q.l-1, q.r, q.a, q.d);
        } else {
            std::cout << st.query(q.i-1, q.i).value << '\n';
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
