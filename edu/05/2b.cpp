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
        integer s = 1;
        integer p = 1;
    };

    static constexpr unsigned M = 1000000007;

public:
    explicit SegmentTree(size_t size)
        : size_(1)
    {
        while (size_ < size)
            size_ *= 2;

        nodes_.resize(2 * size_);

        initialize(1, 0, size_);
    }

    void multiply(size_t lower_bound, size_t upper_bound, unsigned value)
    {
        multiply(lower_bound, upper_bound, value, 1, 0, size_);
    }

    integer sum(size_t lower_bound, size_t upper_bound) const
    {
        return sum(lower_bound, upper_bound, 1, 0, size_);
    }

private:
    void initialize(size_t x, size_t lx, size_t rx)
    {
        if (lx + 1 == rx)
            return;

        const size_t mx = (lx + rx) / 2;
        initialize(x<<1|0, lx, mx);
        initialize(x<<1|1, mx, rx);

        nodes_[x].s = nodes_[x<<1|0].s + nodes_[x<<1|1].s;
    }

    void multiply(size_t lb, size_t ub, unsigned v, size_t x, size_t lx, size_t rx)
    {
        if (rx <= lb || ub <= lx)
            return;

        if (lb <= lx && rx <= ub) {
            nodes_[x].p = nodes_[x].p * v % M;
            nodes_[x].s = nodes_[x].s * v % M;
            return;
        }

        const size_t mx = (lx + rx) / 2;
        multiply(lb, ub, v, x<<1|0, lx, mx);
        multiply(lb, ub, v, x<<1|1, mx, rx);

        nodes_[x].s = (nodes_[x<<1|0].s + nodes_[x<<1|1].s) % M * nodes_[x].p % M;
    }

    integer sum(size_t lb, size_t ub, size_t x, size_t lx, size_t rx) const
    {
        if (rx <= lb || ub <= lx)
            return 0;

        if (lb <= lx && rx <= ub)
            return nodes_[x].s;

        const size_t mx = (lx + rx) / 2;
        return (sum(lb, ub, x<<1|0, lx, mx) + sum(lb, ub, x<<1|1, mx, rx)) % M * nodes_[x].p % M;
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
            st.multiply(r.x, r.y, r.z);
        } else {
            answer(st.sum(r.x, r.y));
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
