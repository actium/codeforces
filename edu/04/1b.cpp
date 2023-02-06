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
    unsigned x;
    unsigned y;
};

std::istream& operator >>(std::istream& input, Query& v)
{
    return input >> v.t >> v.x >> v.y;
}

void answer(unsigned x)
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

void solve(const std::vector<unsigned>& a, const std::vector<Query>& q)
{
    SegmentTree<unsigned, decltype(&std::min<unsigned>)> st(a, &std::min<unsigned>);
    for (const Query& r : q)
        r.t == 1 ? st.set(r.x, r.y) : answer(st.combine(r.x, r.y - 1));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<unsigned> a(n);
    std::cin >> a;

    std::vector<Query> q(m);
    std::cin >> q;

    solve(a, q);

    return 0;
}
