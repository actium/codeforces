#include <iostream>
#include <utility>
#include <vector>

#include <cassert>
#include <cstdint>

class DisjointSetUnion {
public:
    explicit DisjointSetUnion(unsigned size)
        : size_(size)
        , data_(size, -1)
    {}

    unsigned size() const noexcept
    {
        return size_;
    }

    unsigned size(unsigned x) noexcept
    {
        return -data_[locate(x)];
    }

    unsigned locate(unsigned x) noexcept
    {
        unsigned rx = x;
        while (data_[rx] >= 0)
            rx = data_[rx];

        while (data_[x] >= 0)
            x = std::exchange(data_[x], rx);

        return rx;
    }

    bool unite(unsigned u, unsigned v)
    {
        unsigned ru = locate(u), rv = locate(v);
        if (ru == rv)
            return false;

        if (data_[ru] > data_[rv])
            std::swap(ru, rv);

        data_[ru] += data_[rv];
        data_[rv] = ru;
        --size_;

        return true;
    }

private:
    unsigned size_;

    std::vector<int> data_;

}; // class DisjointSetUnion

namespace modular_arithmetic {

    template <unsigned M>
    class Integer {
        static_assert(M != 0, "modulus must be non-zero");

    public:
        static constexpr unsigned modulus = M;

        constexpr Integer() noexcept
            : residue_(0)
        {}

        constexpr Integer(long long value) noexcept
            : residue_(value < 0 ? value % modulus + modulus : value % modulus)
        {}

        [[nodiscard]] constexpr operator unsigned() const noexcept
        {
            return residue_;
        }

        constexpr Integer& operator +=(const Integer& rhs) noexcept
        {
            if (modulus - residue_ <= rhs.residue_)
                residue_ -= modulus;

            residue_ += rhs.residue_;
            return *this;
        }

        constexpr Integer& operator -=(const Integer& rhs) noexcept
        {
            if (residue_ < rhs.residue_)
                residue_ += modulus;

            residue_ -= rhs.residue_;
            return *this;
        }

        constexpr Integer& operator *=(const Integer& rhs) noexcept
        {
            residue_ = static_cast<uint64_t>(residue_) * rhs.residue_ % modulus;
            return *this;
        }

        constexpr Integer& operator /=(const Integer& rhs) noexcept
        {
            return *this *= rhs.invert();
        }

        constexpr Integer& operator ++() noexcept
        {
            if (++residue_ == modulus)
                residue_ = 0;

            return *this;
        }

        constexpr Integer& operator --() noexcept
        {
            if (residue_-- == 0)
                residue_ = modulus - 1;

            return *this;
        }

        constexpr void swap(Integer& other) noexcept
        {
            std::swap(residue_, other.residue_);
        }

        [[nodiscard]] constexpr Integer raise(int power) const noexcept
        {
            if (power < 0) {
                assert(residue_ != 0);
                assert(modulus > 1);
                power = static_cast<uint64_t>(-power) * (modulus - 2) % (modulus - 1);
            }

            Integer result = 1;
            for (Integer base = *this; power != 0; power >>= 1) {
                if ((power & 1) != 0)
                    result *= base;

                base *= base;
            }
            return result;
        }

        [[nodiscard]] constexpr Integer invert() const noexcept
        {
            assert(residue_ != 0);

            const auto is_prime = [](unsigned number) {
                if (number < 2)
                    return false;

                for (unsigned i = 2; i * i <= number; ++i) {
                    if (number % i == 0)
                        return false;
                }
                return true;
            };

            if constexpr (is_prime(modulus)) {
                return raise(modulus - 2);
            } else {
                int64_t x = 1, y = 0, a = residue_, b = modulus;
                while (b != 0) {
                    const int64_t t = a / b;
                    a = std::exchange(b, a - t * b);
                    x = std::exchange(y, x - t * y);
                }
                assert(b == 1 && "value is not coprime to modulus");
                return x;
            }
        }

    private:
        unsigned residue_;

    }; // class Integer<M>

    // returns true if the operands are congruent modulo M, false otherwise
    template <unsigned M>
    constexpr bool operator ==(const Integer<M>& lhs, const Integer<M>& rhs) noexcept
    {
        return static_cast<unsigned>(lhs) == static_cast<unsigned>(rhs);
    }

    // returns true if the operands are not congruent modulo M, false otherwise
    template <unsigned M>
    constexpr bool operator !=(const Integer<M>& lhs, const Integer<M>& rhs) noexcept
    {
        return static_cast<unsigned>(lhs) != static_cast<unsigned>(rhs);
    }

    template <unsigned M>
    constexpr Integer<M> operator +(const Integer<M>& number) noexcept
    {
        return number;
    }

    template <unsigned M>
    constexpr Integer<M> operator -(const Integer<M>& number) noexcept
    {
        return M - static_cast<unsigned>(number);
    }

    template <unsigned M>
    constexpr Integer<M> operator +(const Integer<M>& lhs, const Integer<M>& rhs) noexcept
    {
        return Integer<M>(lhs) += rhs;
    }

    template <typename T, unsigned M>
    constexpr Integer<M> operator +(const Integer<M>& lhs, T rhs) noexcept
    {
        return Integer<M>(lhs) += rhs;
    }

    template <typename T, unsigned M>
    constexpr Integer<M> operator +(T&& lhs, const Integer<M>& rhs) noexcept
    {
        return Integer<M>(lhs) += rhs;
    }

    template <unsigned M>
    constexpr Integer<M> operator -(const Integer<M>& lhs, const Integer<M>& rhs) noexcept
    {
        return Integer<M>(lhs) -= rhs;
    }

    template <typename T, unsigned M>
    constexpr Integer<M> operator -(const Integer<M>& lhs, T rhs) noexcept
    {
        return Integer<M>(lhs) -= rhs;
    }

    template <typename T, unsigned M>
    constexpr Integer<M> operator -(T&& lhs, const Integer<M>& rhs) noexcept
    {
        return Integer<M>(lhs) -= rhs;
    }

    template <unsigned M>
    constexpr Integer<M> operator *(const Integer<M>& lhs, const Integer<M>& rhs) noexcept
    {
        return Integer<M>(lhs) *= rhs;
    }

    template <typename T, unsigned M>
    constexpr Integer<M> operator *(const Integer<M>& lhs, T rhs) noexcept
    {
        return Integer<M>(lhs) *= rhs;
    }

    template <typename T, unsigned M>
    constexpr Integer<M> operator *(T&& lhs, const Integer<M>& rhs) noexcept
    {
        return Integer<M>(lhs) *= rhs;
    }

    template <unsigned M>
    constexpr Integer<M> operator /(const Integer<M>& lhs, const Integer<M>& rhs) noexcept
    {
        return Integer<M>(lhs) /= rhs;
    }

    template <typename T, unsigned M>
    constexpr Integer<M> operator /(const Integer<M>& lhs, T rhs) noexcept
    {
        return Integer<M>(lhs) /= rhs;
    }

    template <typename T, unsigned M>
    constexpr Integer<M> operator /(T&& lhs, const Integer<M>& rhs) noexcept
    {
        return Integer<M>(lhs) /= rhs;
    }

    template <unsigned M>
    constexpr Integer<M> operator ++(Integer<M>& number, int) noexcept
    {
        const Integer<M> s = number;
        ++number;
        return s;
    }

    template <unsigned M>
    constexpr Integer<M> operator --(Integer<M>& number, int) noexcept
    {
        const Integer<M> s = number;
        --number;
        return s;
    }

    template <unsigned M>
    std::istream& operator >>(std::istream& input, Integer<M>& number)
    {
        long long value;
        input >> value;
        number = value;
        return input;
    }

    template <unsigned M>
    std::ostream& operator <<(std::ostream& output, const Integer<M>& number)
    {
        return output << static_cast<unsigned>(number);
    }

} // namespace modular_arithmetic

using integer = modular_arithmetic::Integer<1000000007>;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(DisjointSetUnion& dsu, size_t n, size_t k)
{
    std::vector<unsigned> c(n);
    for (size_t i = 0; i < n; ++i)
        c[dsu.locate(i)] = dsu.size(i);

    integer q = integer(n).raise(k);
    for (size_t i = 0; i < n; ++i)
        q -= integer(c[i]).raise(k);

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n, k;
    std::cin >> n >> k;

    DisjointSetUnion dsu(n);
    for (size_t i = 1; i < n; ++i) {
        unsigned u, v, x;
        std::cin >> u >> v >> x;

        if (x == 0)
            dsu.unite(u-1, v-1);
    }

    solve(dsu, n, k);

    return 0;
}
