#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
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

    void invert(size_t index)
    {
        invert(index, 1, 0, size_);
    }

    T sum(size_t lower_bound, size_t upper_bound) const
    {
        return sum(lower_bound, upper_bound, 1, 0, size_);
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

    T sum(size_t lb, size_t ub, size_t x, size_t lx, size_t rx) const
    {
        if (rx <= lb || ub <= lx)
            return 0;

        if (lb <= lx && rx <= ub)
            return nodes_[x];

        const size_t mx = (lx + rx) / 2;
        return sum(lb, ub, x<<1|0, lx, mx) + sum(lb, ub, x<<1|1, mx, rx);
    }

private:
    size_t size_;

    std::vector<T> nodes_;

}; // class SegmentTree<T>

void solve(const std::vector<unsigned>& a)
{
    const size_t m = a.size(), n = m / 2;

    std::vector<unsigned> r(n), v(n, m);

    SegmentTree<unsigned> st(m);
    for (size_t i = 0; i < m; ++i) {
        const size_t x = a[i] - 1;
        if (v[x] == m) {
            v[x] = i;
        } else {
            r[x] = st.sum(v[x], i);
            st.invert(v[x]);
        }
    }

    answer(r);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(2 * n);
    std::cin >> a;

    solve(a);

    return 0;
}
