#include <iostream>
#include <utility>
#include <vector>

#include <cassert>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

template <typename T>
class BinaryIndexedTree {
public:
    explicit BinaryIndexedTree(unsigned size)
        : nodes_(1 + size)
    {}

    template <typename U>
    void update(unsigned index, U delta)
    {
        for (++index; index < nodes_.size(); index += index & -index)
            nodes_[index] += delta;
    }

    // returns the sum of elements in the range [range_begin; range_end) (0-based)
    T sum(unsigned range_begin, unsigned range_end) const
    {
        auto sum = T();
        while (range_end > range_begin) {
            sum += nodes_[range_end];
            range_end &= range_end - 1;
        }
        while (range_begin > range_end) {
            sum -= nodes_[range_begin];
            range_begin &= range_begin - 1;
        }
        return sum;
    }

private:
    std::vector<T> nodes_;

}; // class BinaryIndexedTree<T>

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
                    x = std::exchange(y, x - a / b * y);
                    a = std::exchange(b, a % b);
                }
                assert(a == 1 && "value is not coprime to modulus");
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

void solve(const std::vector<unsigned>& p)
{
    const size_t n = p.size();

    BinaryIndexedTree<integer> bit(n + 1);
    bit.update(1, 1);
    for (size_t i = n; i > 0; --i) {
        bit.update(i, bit.sum(1, i));
        if (p[i-1] != i)
            bit.update(p[i-1], bit.sum(i, i+1));
    }

    answer(2 * bit.sum(1, n+1));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<unsigned> p(n);
    std::cin >> p;

    solve(p);

    return 0;
}
