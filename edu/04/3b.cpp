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
    explicit SegmentTree(size_t size, T value)
        : size_(1)
    {
        while (size_ < size)
            size_ *= 2;

        nodes_.resize(2 * size_);

        for (size_t i = 0; i < size; ++i)
            nodes_[size_ + i] = value;

        for (size_t i = size_ - 1; i > 0; --i)
            nodes_[i] = nodes_[i<<1|0] + nodes_[i<<1|1];
    }

    void invert(size_t index)
    {
        invert(index, 1, 0, size_);
    }

    size_t lookup(T target) const
    {
        return lookup(target, 1, 0, size_);
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

    size_t lookup(T v, size_t x, size_t lx, size_t rx) const
    {
        if (lx + 1 == rx)
            return lx;

        const unsigned d = nodes_[x * 2];

        const size_t mx = (lx + rx) / 2;
        return v < d ? lookup(v, x<<1|0, lx, mx) : lookup(v - d, x<<1|1, mx, rx);
    }

private:
    size_t size_;

    std::vector<T> nodes_;

}; // class SegmentTree<T>

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> r(n);

    SegmentTree<unsigned> st(n, 1);
    for (size_t i = 0; i < n; ++i) {
        const size_t x = st.lookup(a[n-1-i]);
        r[n-1-i] = n - x;
        st.invert(x);
    }

    answer(r);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);

    return 0;
}
