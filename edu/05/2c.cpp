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
    input >> v.t >> v.x >> v.y;
    return v.t == 1 ? input >> v.z : input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

class SegmentTree {
    struct Node {
        unsigned s = 0;
        unsigned p = 0;
    };

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

    unsigned compute(size_t lower_bound, size_t upper_bound) const
    {
        return compute(lower_bound, upper_bound, 1, 0, size_);
    }

private:
    void update(size_t lb, size_t ub, unsigned v, size_t x, size_t lx, size_t rx)
    {
        if (rx <= lb || ub <= lx)
            return;

        if (lb <= lx && rx <= ub) {
            nodes_[x].p |= v;
            nodes_[x].s |= v;
            return;
        }

        const size_t mx = (lx + rx) / 2;
        update(lb, ub, v, x<<1|0, lx, mx);
        update(lb, ub, v, x<<1|1, mx, rx);

        nodes_[x].s = nodes_[x<<1|0].s & nodes_[x<<1|1].s | nodes_[x].p;
    }

    unsigned compute(size_t lb, size_t ub, size_t x, size_t lx, size_t rx) const
    {
        if (rx <= lb || ub <= lx)
            return ~0u;

        if (lb <= lx && rx <= ub)
            return nodes_[x].s;

        const size_t mx = (lx + rx) / 2;
        return compute(lb, ub, x<<1|0, lx, mx) & compute(lb, ub, x<<1|1, mx, rx) | nodes_[x].p;
    }

private:
    size_t size_;

    std::vector<Node> nodes_;

}; // class SegmentTree

void solve(size_t n, const std::vector<Query>& q)
{
    SegmentTree st(n);
    for (const Query& r : q) {
        if (r.t == 1) {
            st.update(r.x, r.y, r.z);
        } else {
            answer(st.compute(r.x, r.y));
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
