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

    void set(size_t index)
    {
        set(index, 1, 0, size_);
    }

    T sum(size_t lower_bound) const
    {
        return sum(lower_bound, 1, 0, size_);
    }

private:
    void set(size_t index, size_t x, size_t lx, size_t rx)
    {
        if (lx + 1 == rx) {
            nodes_[x] = 1;
            return;
        }

        const size_t mx = (lx + rx) / 2;
        if (index < mx) {
            set(index, x<<1|0, lx, mx);
        } else {
            set(index, x<<1|1, mx, rx);
        }

        nodes_[x] = nodes_[x<<1|0] + nodes_[x<<1|1];
    }

    T sum(size_t lb, size_t x, size_t lx, size_t rx) const
    {
        if (rx <= lb || lx == size_)
            return 0;

        if (lb <= lx)
            return nodes_[x];

        const size_t mx = (lx + rx) / 2;
        return sum(lb, x<<1|0, lx, mx) + sum(lb, x<<1|1, mx, rx);
    }

private:
    size_t size_;

    std::vector<T> nodes_;

}; // class SegmentTree<T>

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::vector<unsigned> r(n);

    SegmentTree<unsigned> st(n);
    for (size_t i = 0; i < n; ++i) {
        r[i] = st.sum(a[i]);
        st.set(a[i] - 1);
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
