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
    unsigned z;
};

std::istream& operator >>(std::istream& input, Query& v)
{
    input >> v.t >> v.x;
    return v.t == 1 ? input >> v.y >> v.z : input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

class SegmentTree {
public:
    explicit SegmentTree(size_t size)
        : size_(1)
    {
        while (size_ < size)
            size_ *= 2;

        nodes_.resize(2 * size_);
    }

    void update(size_t lower_bound, size_t upper_bound, unsigned value)
    {
        update(lower_bound, upper_bound, value, 1, 0, size_);
    }

    unsigned get(size_t index) const
    {
        return get(index, 1, 0, size_);
    }

private:
    void update(size_t lb, size_t ub, unsigned v, size_t x, size_t lx, size_t rx)
    {
        if (rx <= lb || ub <= lx)
            return;

        if (lb <= lx && rx <= ub) {
            nodes_[x] = std::max(nodes_[x], v);
            return;
        }

        const size_t mx = (lx + rx) / 2;
        update(lb, ub, v, x<<1|0, lx, mx);
        update(lb, ub, v, x<<1|1, mx, rx);
    }

    unsigned get(size_t index, size_t x, size_t lx, size_t rx) const
    {
        if (lx + 1 == rx)
            return nodes_[x];

        const size_t mx = (lx + rx) / 2;
        return std::max(index < mx ? get(index, x<<1|0, lx, mx) : get(index, x<<1|1, mx, rx), nodes_[x]);
    }

private:
    size_t size_;

    std::vector<unsigned> nodes_;

}; // class SegmentTree

void solve(size_t n, const std::vector<Query>& q)
{
    SegmentTree st(n);
    for (const Query& r : q) {
        if (r.t == 1) {
            st.update(r.x, r.y, r.z);
        } else {
            answer(st.get(r.x));
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