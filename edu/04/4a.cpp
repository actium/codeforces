#include <array>
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

void answer(int x)
{
    std::cout << x << '\n';
}

template <typename T>
class SegmentTree {
    using node_t = std::array<T, 2>;

public:
    template <typename U = T>
    explicit SegmentTree(const std::vector<U>& data)
        : size_(1)
    {
        while (size_ < data.size())
            size_ *= 2;

        nodes_.resize(2 * size_);

        for (size_t i = 0; i < data.size(); ++i)
            nodes_[size_ + i][i % 2] = data[i];

        for (size_t i = size_ - 1; i > 0; --i)
            nodes_[i] = combine(nodes_[i<<1|0], nodes_[i<<1|1]);
    }

    void set(size_t index, T value)
    {
        set(index, value, 1, 0, size_);
    }

    T sum(size_t lower_bound, size_t upper_bound) const
    {
        const node_t s = sum(lower_bound, upper_bound, 1, 0, size_);
        return lower_bound % 2 == 0 ? s[0] - s[1] : s[1] - s[0];
    }

private:
    static node_t combine(const node_t& lhs, const node_t& rhs)
    {
        return {lhs[0] + rhs[0], lhs[1] + rhs[1]};
    }

    void set(size_t index, T value, size_t x, size_t lx, size_t rx)
    {
        if (lx + 1 == rx) {
            nodes_[x][x % 2] = value;
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

    node_t sum(size_t lb, size_t ub, size_t x, size_t lx, size_t rx) const
    {
        if (rx <= lb || ub <= lx)
            return {0, 0};

        if (lb <= lx && rx <= ub)
            return nodes_[x];

        const size_t mx = (lx + rx) / 2;
        return combine(sum(lb, ub, x<<1|0, lx, mx), sum(lb, ub, x<<1|1, mx, rx));
    }

private:
    size_t size_;

    std::vector<node_t> nodes_;

}; // class SegmentTree<T>

void solve(const std::vector<unsigned>& a, const std::vector<Query>& q)
{
    SegmentTree<int> st(a);
    for (const Query& r : q) {
        if (r.t == 0) {
            st.set(r.x - 1, r.y);
        } else {
            answer(st.sum(r.x - 1, r.y));
        }
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    size_t m;
    std::cin >> m;

    std::vector<Query> q(m);
    std::cin >> q;

    solve(a, q);

    return 0;
}
