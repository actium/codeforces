#include <deque>
#include <iostream>
#include <optional>
#include <vector>

template <typename Value, typename Operation, typename Point = unsigned>
class SparseSegmentTree {
    struct Range {
        Point begin;
        Point end;
    };

    class Segment {
    public:
        explicit Segment(const Range& range)
            : range_(range)
            , value_(range.end - range.begin)
        {}

        void update(Point point, const Operation& operation)
        {
            if (point < range_.begin || point >= range_.end)
                return;

            if (range_.begin + 1 == range_.end) {
                aggregate_operation(operation);
            } else {
                propagate_operation();
                select_subsegment(point)->update(point, operation);
                recompute_value();
            }
        }

        void update(const Range& range, const Operation& operation)
        {
            if (range.end <= range_.begin || range_.end <= range.begin)
                return;

            if (range.begin <= range_.begin && range_.end <= range.end) {
                aggregate_operation(operation);
            } else {
                propagate_operation();
                subsegments_[0]->update(range, operation);
                subsegments_[1]->update(range, operation);
                recompute_value();
            }
        }

        Value query(Point point)
        {
            if (point < range_.begin || point >= range_.end)
                return Value();

            if (range_.begin + 1 == range_.end)
                return value_;

            propagate_operation();
            return select_subsegment(point)->query(point);
        }

        Value query(const Range& range)
        {
            if (range.end <= range_.begin || range_.end <= range.begin)
                return Value();

            if (range.begin <= range_.begin && range_.end <= range.end)
                return value_;

            propagate_operation();
            return Value(subsegments_[0]->query(range), subsegments_[1]->query(range));
        }

        int search(int height)
        {
            if (range_.begin + 1 == range_.end)
                return range_.begin;

            propagate_operation();
            return subsegments_[0]->value_.prefix > height ?
                subsegments_[0]->search(height) : subsegments_[1]->search(height - subsegments_[0]->value_.sum);
        }

    private:
        void ensure_subsegments_exist()
        {
            static std::deque<Segment> segment_pool;

            const Point mid_point = (range_.begin + range_.end) / 2;
            if (subsegments_[0] == nullptr)
                subsegments_[0] = &segment_pool.emplace_back(Range{range_.begin, mid_point});
            if (subsegments_[1] == nullptr)
                subsegments_[1] = &segment_pool.emplace_back(Range{mid_point, range_.end});
        }

        Segment* select_subsegment(size_t point) const
        {
            return subsegments_[point >= subsegments_[1]->range_.begin];
        }

        void aggregate_operation(const Operation& operation)
        {
            if (!operation_)
                operation_ = operation;
            else
                operation_->aggregate(operation);

            operation.apply(value_);
        }

        void propagate_operation()
        {
            ensure_subsegments_exist();

            if (operation_) {
                subsegments_[0]->aggregate_operation(*operation_);
                subsegments_[1]->aggregate_operation(*operation_);
                operation_ = std::nullopt;
            }
        }

        void recompute_value()
        {
            value_ = Value(subsegments_[0]->value_, subsegments_[1]->value_);
        }

    private:
        const Range range_;

        Value value_;
        std::optional<Operation> operation_;

        Segment* subsegments_[2] = {};

    }; // class Segment

public:
    SparseSegmentTree(Point range_begin, Point range_end)
        : root_({range_begin, range_end})
    {}

    void update(Point point, const Operation& operation)
    {
        root_.update(point, operation);
    }

    void update(Point range_begin, Point range_end, const Operation& operation)
    {
        root_.update({range_begin, range_end}, operation);
    }

    Value query(Point point)
    {
        return root_.query(point);
    }

    Value query(Point range_begin, Point range_end)
    {
        return root_.query({range_begin, range_end});
    }

    int search(int height)
    {
        return root_.search(height);
    }

private:
    Segment root_;

}; // class SparseSegmentTree<Value, Operation, Point>

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

struct Value {
    unsigned range_size;

    int sum = 0;
    int prefix = 0;

    explicit Value(unsigned range_size)
        : range_size(range_size)
    {}

    Value(const Value& lhs, const Value& rhs)
        : range_size(lhs.range_size + rhs.range_size)
        , sum(lhs.sum + rhs.sum)
        , prefix(std::max(lhs.prefix, lhs.sum + rhs.prefix))
    {}
};

struct Operation {
    int delta;

    explicit Operation(int delta)
        : delta(delta)
    {}

    void aggregate(const Operation& operation)
    {
        delta = operation.delta;
    }

    void apply(Value& target) const
    {
        target.sum = delta * target.range_size;
        target.prefix = std::max(0, target.sum);
    }
};

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    SparseSegmentTree<Value, Operation> st({0, n + 2});

    Query q;
    while (std::cin >> q && q.t != 'E') {
        if (q.t == 'I') {
            st.update(q.a, q.b + 1, Operation(q.d));
        } else {
            std::cout << st.search(q.h) - 1 << '\n';
        }
    }

    return 0;
}
