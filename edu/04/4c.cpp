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
};

std::istream& operator >>(std::istream& input, Query& v)
{
    return input >> v.t >> v.x >> v.y;
}

void answer(integer x)
{
    std::cout << x << '\n';
}

template <size_t K>
class SegmentTree {
    struct Node {
        unsigned f[K] = {};
        integer k = 0;
    };

public:
    explicit SegmentTree(size_t size)
        : size_(1)
    {
        while (size_ < size)
            size_ *= 2;

        nodes_.resize(2 * size_);
    }

    void set(size_t index, unsigned value)
    {
        set(index, value, 1, 0, size_);
    }

    integer count(size_t lower_bound, size_t upper_bound) const
    {
        return count(lower_bound, upper_bound, 1, 0, size_).k;
    }

private:
    static Node combine(const Node& lhs, const Node& rhs)
    {
        Node node;
        {
            for (size_t i = 0; i < K; ++i)
                node.f[i] = lhs.f[i] + rhs.f[i];

            node.k = lhs.k + rhs.k;
            for (size_t i = 1; i < K; ++i) {
                for (size_t j = 0; j < i; ++j)
                    node.k += 1ull * lhs.f[i] * rhs.f[j];
            }
        }
        return node;
    }

    void set(size_t index, unsigned value, size_t x, size_t lx, size_t rx)
    {
        if (lx + 1 == rx) {
            nodes_[x] = {};
            ++nodes_[x].f[value - 1];
            return;
        }

        const size_t mx = (lx + rx) / 2;
        if (index < mx) {
            set(index, value, x<<1|0, lx, mx);
        } else {
            set(index, value, x<<1|1, mx, rx);
        }

        nodes_[x] = combine(nodes_[x<<1|0], nodes_[x<<1|1]);
    }

    Node count(size_t lb, size_t ub, size_t x, size_t lx, size_t rx) const
    {
        if (rx <= lb || ub <= lx)
            return {};

        if (lb <= lx && rx <= ub)
            return nodes_[x];

        const size_t mx = (lx + rx) / 2;
        return combine(count(lb, ub, x<<1|0, lx, mx), count(lb, ub, x<<1|1, mx, rx));
    }

private:
    size_t size_;

    std::vector<Node> nodes_;

}; // class SegmentTree

void solve(const std::vector<unsigned>& a, const std::vector<Query>& q)
{
    const size_t n = a.size();

    SegmentTree<40> st(n);
    for (size_t i = 0; i < n; ++i)
        st.set(i, a[i]);

    for (const Query& r : q)
        r.t == 1 ? answer(st.count(r.x - 1, r.y)) : st.set(r.x - 1, r.y);
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
