#include <iostream>
#include <optional>

struct Query {
    char t;
    union {
        struct {
            unsigned a;
            unsigned b;
            int d;
        };
        unsigned h;
    };
};

std::istream& operator >>(std::istream& input, Query& q)
{
    input >> q.t;
    if (q.t == 'I')
        input >> q.a >> q.b >> q.d;
    if (q.t == 'Q')
        input >> q.h;
    return input;
}

template <typename Node, typename Update>
class SegmentTree {
    class Segment {
    public:
        Segment(unsigned range_begin, unsigned range_end)
            : range_begin_(range_begin)
            , range_end_(range_end)
            , node_(range_end - range_begin)
        {}

        template <typename... Ts>
        void update_point(unsigned index, Ts&&... arguments)
        {
            if (range_begin_ + 1 == range_end_) {
                aggregate_updates(Update(std::forward<Ts>(arguments)...));
                return;
            }

            propagate_updates();

            update_point(select_subsegment(index), index, std::forward<Ts>(arguments)...);
            node_ = Node(subsegments_[0]->node_, subsegments_[1]->node_);
        }

        template <typename... Ts>
        void update_range(unsigned range_begin, unsigned range_end, Ts&&... arguments)
        {
            if (range_end <= range_begin_ || range_end_ <= range_begin)
                return;

            if (range_begin <= range_begin_ && range_end_ <= range_end) {
                aggregate_updates(Update(std::forward<Ts>(arguments)...));
                return;
            }

            propagate_updates();

            subsegments_[0]->update_range(range_begin, range_end, std::forward<Ts>(arguments)...);
            subsegments_[1]->update_range(range_begin, range_end, std::forward<Ts>(arguments)...);
            node_ = Node(subsegments_[0]->node_, subsegments_[1]->node_);
        }

        std::optional<Node> query_point(unsigned index)
        {
            if (range_begin_ + 1 == range_end_)
                return node_;

            propagate_updates();

            return select_subsegment(index)->query_point(index);
        }

        std::optional<Node> query_range(unsigned range_begin, unsigned range_end)
        {
            if (range_end <= range_begin_ || range_end_ <= range_begin)
                return std::nullopt;

            if (range_begin <= range_begin_ && range_end_ <= range_end)
                return node_;

            propagate_updates();

            const std::optional<Node> lhs = subsegments_[0]->query_range(range_begin, range_end);
            const std::optional<Node> rhs = subsegments_[1]->query_range(range_begin, range_end);
            if (lhs && rhs)
                return Node(*lhs, *rhs);

            return lhs ? lhs : rhs;
        }

        template <typename F>
        std::optional<unsigned> search(F&& predicate)
        {
            if (range_begin_ + 1 == range_end_)
                return range_begin_;

            propagate_updates();

            return predicate(subsegments_[0]->range_begin_, subsegments_[0]->range_end_, subsegments_[0]->node_) ?
                subsegments_[0]->search(predicate) : subsegments_[1]->search(predicate);
        }

    private:
        Segment* select_subsegment(unsigned index)
        {
            return index < subsegments_[0]->range_end_ ? subsegments_[0] : subsegments_[1];
        }

        void aggregate_updates(const Update& update)
        {
            if (!update_)
                update_ = update;
            else
                update_->aggregate(update);

            update.apply(node_);
        }

        void propagate_updates()
        {
            const unsigned mid_point = (range_begin_ + range_end_) / 2;
            if (subsegments_[0] == nullptr)
                subsegments_[0] = new Segment(range_begin_, mid_point);
            if (subsegments_[1] == nullptr)
                subsegments_[1] = new Segment(mid_point, range_end_);

            if (update_) {
                subsegments_[0]->aggregate_updates(*update_);
                subsegments_[1]->aggregate_updates(*update_);

                update_ = std::nullopt;
            }
        }

    private:
        const unsigned range_begin_;
        const unsigned range_end_;

        Node node_;
        std::optional<Update> update_;

        Segment* subsegments_[2] = {};

    }; // class Segment

public:
    explicit SegmentTree(unsigned size)
        : size_(size)
        , root_(0, size)
    {}

    template <typename... Ts>
    void update_point(unsigned index, Ts&&... arguments)
    {
        root_.update_point(index, std::forward<Ts>(arguments)...);
    }

    template <typename... Ts>
    void update_range(unsigned range_begin, unsigned range_end, Ts&&... arguments)
    {
        root_.update_range(range_begin, range_end, std::forward<Ts>(arguments)...);
    }

    std::optional<Node> query_point(unsigned index)
    {
        return root_.query_point(index);
    }

    std::optional<Node> query_range(unsigned range_begin, unsigned range_end)
    {
        return root_.query_range(range_begin, range_end);
    }

    template <typename F>
    std::optional<unsigned> search(F&& predicate)
    {
        return root_.search(predicate);
    }

private:
    const unsigned size_;

    Segment root_;

}; // class SegmentTree<Node, Update>

struct Node {
    unsigned range_size;

    int sum = 0;
    int prefix = 0;

    explicit Node(unsigned range_size)
        : range_size(range_size)
    {}

    Node(const Node& lhs, const Node& rhs)
        : range_size(lhs.range_size + rhs.range_size)
        , sum(lhs.sum + rhs.sum)
        , prefix(std::max(lhs.prefix, lhs.sum + rhs.prefix))
    {}

    void update(int delta)
    {
        sum = delta * range_size;
        prefix = std::max(0, sum);
    }
};

struct Update {
    int delta = 0;

    explicit Update(int delta)
        : delta(delta)
    {}

    void aggregate(const Update& update)
    {
        delta = update.delta;
    }

    void apply(Node& target_node) const
    {
        target_node.update(delta);
    }
};

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    SegmentTree<Node, Update> st(1 + n + 1);

    Query q;
    for (std::cin >> q; q.t != 'E'; std::cin >> q) {
        if (q.t == 'I') {
            st.update_range(q.a, q.b + 1, q.d);
        } else {
            int height = q.h;

            const auto predicate = [&](unsigned, unsigned, const Node& node) {
                if (node.prefix > height)
                    return true;

                height -= node.sum;
                return false;
            };

            std::cout << static_cast<int>(*st.search(predicate) - 1) << '\n';
        }
    }

    return 0;
}
