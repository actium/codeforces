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
    unsigned t;
    unsigned x;
    unsigned y;
    integer z;
};

std::istream& operator >>(std::istream& input, Query& v)
{
    input >> v.t >> v.x;
    return v.t == 1 ? input >> v.y >> v.z : input;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

template <typename T>
class SegmentTree {
public:
    explicit SegmentTree(size_t size)
        : size_(1)
    {
        while (size_ < size)
            size_ *= 2;

        nodes_.resize(2 * size_);
    }

    void add(size_t index, T delta)
    {
        add(index, delta, 1, 0, size_);
    }

    T sum(size_t upper_bound) const
    {
        return sum(upper_bound, 1, 0, size_);
    }

private:
    void add(size_t index, T delta, size_t x, size_t lx, size_t rx)
    {
        if (lx + 1 == rx) {
            nodes_[x] += delta;
            return;
        }

        const size_t mx = (lx + rx) / 2;
        if (index < mx) {
            add(index, delta, x<<1|0, lx, mx);
        } else {
            add(index, delta, x<<1|1, mx, rx);
        }

        nodes_[x] = nodes_[x<<1|0] + nodes_[x<<1|1];
    }

    T sum(size_t ub, size_t x, size_t lx, size_t rx) const
    {
        if (ub <= lx)
            return 0;

        if (rx <= ub)
            return nodes_[x];

        const size_t mx = (lx + rx) / 2;
        return sum(ub, x<<1|0, lx, mx) + sum(ub, x<<1|1, mx, rx);
    }

private:
    size_t size_;

    std::vector<T> nodes_;

}; // class SegmentTree<T>

void solve(size_t n, const std::vector<Query>& q)
{
    SegmentTree<integer> st(n);
    for (const Query& r : q) {
        if (r.t == 1) {
            st.add(r.x, +r.z);
            if (r.y < n)
                st.add(r.y, -r.z);
        } else {
            answer(st.sum(r.x + 1));
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<Query> q(m);
    std::cin >> q;

    solve(n, q);

    return 0;
}
