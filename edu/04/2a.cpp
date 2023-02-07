#include <iostream>
#include <vector>

using integer = long long;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Query {
    size_t i;
    int v;
};

std::istream& operator >>(std::istream& input, Query& v)
{
    return input >> v.i >> v.v;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

template <typename T, typename F>
class SegmentTree {
public:
    template <typename U>
    SegmentTree(const std::vector<U>& data, F&& combine)
        : size_(data.size())
        , combine_(std::forward<F>(combine))
    {
        data_.reserve(2 * size_);
        data_.resize(size_);
        data_.insert(data_.end(), data.cbegin(), data.cend());

        for (size_t i = size_ - 1; i > 0; --i) {
            data_[i] = combine_(data_[i<<1], data_[i<<1|1]);
        }
    }

    size_t size() const noexcept
    {
        return size_;
    }

    void set(size_t index, T value)
    {
        index += size_;
        data_[index] = value;

        while (index > 1) {
            const size_t parent = index >> 1;
            data_[parent] = combine_(data_[index], data_[index^1]);
            index = parent;
        }
    }

    T combine(size_t left_index, size_t right_index) const
    {
        size_t lb = size_ + left_index;
        T left = data_[lb++];

        if (left_index == right_index)
            return left;

        size_t ub = size_ + right_index + 1;
        T right = data_[--ub];

        while (lb < ub) {
            if (lb & 1)
                left = combine_(left, data_[lb++]);

            if (ub & 1)
                right = combine_(right, data_[--ub]);

            lb >>= 1, ub >>= 1;
        }

        return combine_(left, right);
    }

private:
    const size_t size_;
    const F combine_;

    std::vector<T> data_;

}; // class SegmentTree<T>

void solve(const std::vector<int>& a, const std::vector<Query>& q)
{
    const size_t n = a.size();

    struct Node {
        size_t i;
        integer t;
        integer p;
        integer s;
        integer x;

        Node() = default;

        Node(size_t i, int t)
            : i(i)
            , t(t)
            , p(std::max(t, 0))
            , s(std::max(t, 0))
            , x(std::max(t, 0))
        {}
    };

    std::vector<Node> b(n);
    for (size_t i = 0; i < n; ++i)
        b[i] = Node(i, a[i]);

    const auto combine_i = [](const Node& a, const Node& b) -> Node {
        Node c;
        c.i = a.i;
        c.t = a.t + b.t;
        c.p = std::max(a.p, a.t + b.p);
        c.s = std::max(a.s + b.t, b.s);
        c.x = std::max(std::max(a.x, b.x), a.s + b.p);
        return c;
    };

    const auto combine = [&combine_i](const Node& a, const Node& b) {
        return a.i < b.i ? combine_i(a, b) : combine_i(b, a);
    };

    SegmentTree<Node, decltype(combine)> st(b, std::move(combine));
    answer(st.combine(0, n - 1).x);
    for (const Query& r : q) {
        st.set(r.i, Node(r.i, r.v));
        answer(st.combine(0, n - 1).x);
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    std::cin >> a;

    std::vector<Query> q(m);
    std::cin >> q;

    solve(a, q);

    return 0;
}
