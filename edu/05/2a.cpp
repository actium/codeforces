#include <iostream>
#include <vector>

using integer = unsigned long long;

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

void answer(integer x)
{
    std::cout << x << '\n';
}

class SegmentTree {
    struct Node {
        integer d = 0;
        integer b = 0;
    };

public:
    explicit SegmentTree(size_t size)
        : size_(1)
    {
        while (size_ < size)
            size_ *= 2;

        nodes_.resize(2 * size_);
    }

    void add(size_t lower_bound, size_t upper_bound, unsigned value)
    {
        add(lower_bound, upper_bound, value, 1, 0, size_);
    }

    integer min(size_t lower_bound, size_t upper_bound) const
    {
        return min(lower_bound, upper_bound, 1, 0, size_);
    }

private:
    void add(size_t lb, size_t ub, unsigned v, size_t x, size_t lx, size_t rx)
    {
        if (rx <= lb || ub <= lx)
            return;

        if (lb <= lx && rx <= ub) {
            nodes_[x].d += v;
            nodes_[x].b += v;
            return;
        }

        const size_t mx = (lx + rx) / 2;
        add(lb, ub, v, x<<1|0, lx, mx);
        add(lb, ub, v, x<<1|1, mx, rx);

        nodes_[x].b = std::min(nodes_[x<<1|0].b, nodes_[x<<1|1].b) + nodes_[x].d;
    }

    integer min(size_t lb, size_t ub, size_t x, size_t lx, size_t rx) const
    {
        if (rx <= lb || ub <= lx)
            return ~integer(0);

        if (lb <= lx && rx <= ub)
            return nodes_[x].b;

        const size_t mx = (lx + rx) / 2;
        return std::min(min(lb, ub, x<<1|0, lx, mx), min(lb, ub, x<<1|1, mx, rx)) + nodes_[x].d;
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
            st.add(r.x, r.y, r.z);
        } else {
            answer(st.min(r.x, r.y));
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
