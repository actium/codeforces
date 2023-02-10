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
    input >> v.t >> v.x;
    return v.t == 1 ? input >> v.y : input;
}

void answer(size_t x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

template <typename T>
class SegmentTree {
public:
    template <typename U = T>
    explicit SegmentTree(const std::vector<U>& data)
        : size_(1)
    {
        while (size_ < data.size())
            size_ *= 2;

        nodes_.resize(2 * size_);

        for (size_t i = 0; i < data.size(); ++i)
            nodes_[size_ + i] = data[i];

        for (size_t i = size_ - 1; i > 0; --i)
            nodes_[i] = std::max(nodes_[i<<1|0], nodes_[i<<1|1]);
    }

    void set(size_t index, T value)
    {
        set(index, value, 1, 0, size_);
    }

    size_t lower_bound(T target) const
    {
        return lower_bound(target, 1, 0, size_);
    }

private:
    void set(size_t index, T value, size_t x, size_t lx, size_t rx)
    {
        if (lx + 1 == rx) {
            nodes_[x] = value;
            return;
        }

        const size_t mx = (lx + rx) / 2;
        if (index < mx) {
            set(index, value, x<<1|0, lx, mx);
        } else {
            set(index, value, x<<1|1, mx, rx);
        }

        nodes_[x] = std::max(nodes_[x<<1|0], nodes_[x<<1|1]);
    }

    size_t lower_bound(T v, size_t x, size_t lx, size_t rx) const
    {
        if (nodes_[x] < v)
            return size_;

        if (lx + 1 == rx)
            return lx;

        const size_t mx = (lx + rx) / 2;

        const size_t p = lower_bound(v, x<<1|0, lx, mx);
        return p < size_ ? p : lower_bound(v, x<<1|1, mx, rx);
    }

private:
    size_t size_;

    std::vector<T> nodes_;

}; // class SegmentTree<T>

void solve(const std::vector<unsigned>& a, const std::vector<Query>& q)
{
    const size_t n = a.size();

    SegmentTree<unsigned> st(a);
    for (const Query& r : q) {
        if (r.t == 1) {
            st.set(r.x, r.y);
        } else {
            const size_t p = st.lower_bound(r.x);
            p < n ? answer(p) : no_answer();
        }
    }
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
