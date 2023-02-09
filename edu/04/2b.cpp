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
};

std::istream& operator >>(std::istream& input, Query& v)
{
    return input >> v.t >> v.x;
}

void answer(size_t x)
{
    std::cout << x << '\n';
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
            nodes_[i] = nodes_[i<<1|0] + nodes_[i<<1|1];
    }

    void invert(size_t index)
    {
        invert(index, 1, 0, size_);
    }

    size_t lookup(size_t rank) const
    {
        return lookup(rank, 1, 0, size_);
    }

private:
    void invert(size_t index, size_t x, size_t lx, size_t rx)
    {
        if (lx + 1 == rx) {
            nodes_[x] ^= 1;
            return;
        }

        const size_t mx = (lx + rx) / 2;
        if (index < mx) {
            invert(index, x<<1|0, lx, mx);
        } else {
            invert(index, x<<1|1, mx, rx);
        }

        nodes_[x] = nodes_[x<<1|0] + nodes_[x<<1|1];
    }

    size_t lookup(size_t rank, size_t x, size_t lx, size_t rx) const
    {
        if (lx + 1 == rx)
            return lx;

        const unsigned d = nodes_[x * 2];

        const size_t mx = (lx + rx) / 2;
        return rank < d ? lookup(rank, x<<1|0, lx, mx) : lookup(rank - d, x<<1|1, mx, rx);
    }

private:
    size_t size_;

    std::vector<T> nodes_;

}; // class SegmentTree<T>

void solve(const std::vector<unsigned>& a, const std::vector<Query>& q)
{
    SegmentTree<unsigned> st(a);
    for (const Query& r : q)
        r.t == 1 ? st.invert(r.x) : answer(st.lookup(r.x));
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
