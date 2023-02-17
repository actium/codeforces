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

class SegmentTree {
public:
    explicit SegmentTree(const std::vector<unsigned>& data)
        : size_(1)
    {
        while (size_ < data.size())
            size_ *= 2;

        nodes_.resize(2 * size_);

        for (size_t i = 0; i < data.size(); ++i)
            nodes_[size_ + i] = uint64_t(1) << data[i];

        for (size_t i = size_ - 1; i > 0; --i)
            nodes_[i] = nodes_[i<<1|0] | nodes_[i<<1|1];
    }

    void set(size_t index, unsigned value)
    {
        set(index, value, 1, 0, size_);
    }

    uint64_t lookup(size_t lower_bound, size_t upper_bound) const
    {
        return lookup(lower_bound, upper_bound, 1, 0, size_);
    }

private:
    void set(size_t index, unsigned value, size_t x, size_t lx, size_t rx)
    {
        if (lx + 1 == rx) {
            nodes_[x] = uint64_t(1) << value;
            return;
        }

        const size_t mx = (lx + rx) / 2;
        if (index < mx) {
            set(index, value, x<<1|0, lx, mx);
        } else {
            set(index, value, x<<1|1, mx, rx);
        }

        nodes_[x] = nodes_[x<<1|0] | nodes_[x<<1|1];
    }

    uint64_t lookup(size_t lb, size_t ub, size_t x, size_t lx, size_t rx) const
    {
        if (rx <= lb || ub <= lx)
            return 0;

        if (lb <= lx && rx <= ub)
            return nodes_[x];

        const size_t mx = (lx + rx) / 2;
        return lookup(lb, ub, x<<1|0, lx, mx) | lookup(lb, ub, x<<1|1, mx, rx);
    }

private:
    size_t size_;

    std::vector<uint64_t> nodes_;

}; // class SegmentTree

void solve(const std::vector<unsigned>& a, const std::vector<Query>& q)
{
    SegmentTree st(a);
    for (const Query& r : q) {
        if (r.t == 1) {
            const unsigned k = __builtin_popcountll(st.lookup(r.x - 1, r.y));
            answer(k);
        } else {
            st.set(r.x - 1, r.y);
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
