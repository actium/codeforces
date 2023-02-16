#include <iostream>
#include <vector>

using range_t = std::pair<unsigned, unsigned>;

unsigned modulus;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

struct Matrix {
    unsigned cells[2][2] = {
        { 1, 0 },
        { 0, 1 },
    };
};

std::istream& operator >>(std::istream& input, Matrix& v)
{
    return input >> v.cells[0][0] >> v.cells[0][1] >> v.cells[1][0] >> v.cells[1][1];
}

Matrix operator *(const Matrix& lhs, const Matrix& rhs)
{
    Matrix v;
    v.cells[0][0] = (1ull * lhs.cells[0][0] * rhs.cells[0][0] + 1ull * lhs.cells[0][1] * rhs.cells[1][0]) % modulus;
    v.cells[0][1] = (1ull * lhs.cells[0][0] * rhs.cells[0][1] + 1ull * lhs.cells[0][1] * rhs.cells[1][1]) % modulus;
    v.cells[1][0] = (1ull * lhs.cells[1][0] * rhs.cells[0][0] + 1ull * lhs.cells[1][1] * rhs.cells[1][0]) % modulus;
    v.cells[1][1] = (1ull * lhs.cells[1][0] * rhs.cells[0][1] + 1ull * lhs.cells[1][1] * rhs.cells[1][1]) % modulus;
    return v;
}

void answer(const Matrix& x)
{
    std::cout << x.cells[0][0] << ' ' << x.cells[0][1] << '\n';
    std::cout << x.cells[1][0] << ' ' << x.cells[1][1] << '\n';
    std::cout << '\n';
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
            nodes_[i] = nodes_[i<<1|0] * nodes_[i<<1|1];
    }

    T product(size_t lower_bound, size_t upper_bound) const
    {
        return product(lower_bound, upper_bound, 1, 0, size_);
    }

private:
    T product(size_t lb, size_t ub, size_t x, size_t lx, size_t rx) const
    {
        if (rx <= lb || ub <= lx)
            return T();

        if (lb <= lx && rx <= ub)
            return nodes_[x];

        const size_t mx = (lx + rx) / 2;
        return product(lb, ub, x<<1|0, lx, mx) * product(lb, ub, x<<1|1, mx, rx);
    }

private:
    size_t size_;

    std::vector<T> nodes_;

}; // class SegmentTree<T>

void solve(const std::vector<Matrix>& a, const std::vector<range_t>& q)
{
    SegmentTree<Matrix> st(a);
    for (const range_t& r : q)
        answer(st.product(r.first - 1, r.second));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::cin >> modulus;

    size_t n, m;
    std::cin >> n >> m;

    std::vector<Matrix> a(n);
    std::cin >> a;

    std::vector<range_t> q(m);
    std::cin >> q;

    solve(a, q);

    return 0;
}
