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
    return v.t == 1 ? input : input >> v.z;
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

        nodes_.resize(2 * size_, ~0u);
    }

    void set(size_t index, unsigned height)
    {
        set(index, height, 1, 0, size_);
    }

    unsigned reset(size_t lower_bound, size_t upper_bound, unsigned height)
    {
        return reset(lower_bound, upper_bound, height, 1, 0, size_);
    }

private:
    void set(size_t index, unsigned height, size_t x, size_t lx, size_t rx)
    {
        if (lx + 1 == rx) {
            nodes_[x] = height;
            return;
        }

        const size_t mx = (lx + rx) / 2;
        if (index < mx) {
            set(index, height, x<<1|0, lx, mx);
        } else {
            set(index, height, x<<1|1, mx, rx);
        }

        nodes_[x] = std::min(nodes_[x<<1|0], nodes_[x<<1|1]);
    }

    unsigned reset(size_t lb, size_t ub, unsigned p, size_t x, size_t lx, size_t rx)
    {
        if (rx <= lb || ub <= lx)
            return 0;

        if (nodes_[x] > p)
            return 0;

        if (lx + 1 == rx) {
            nodes_[x] = ~0u;
            return 1;
        }

        const size_t mx = (lx + rx) / 2;

        const unsigned k = reset(lb, ub, p, x<<1|0, lx, mx) + reset(lb, ub, p, x<<1|1, mx, rx);
        nodes_[x] = std::min(nodes_[x<<1|0], nodes_[x<<1|1]);
        return k;
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
            st.set(r.x, r.y);
        } else {
            answer(st.reset(r.x, r.y, r.z));
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
