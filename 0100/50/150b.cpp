#include <iostream>
#include <utility>

#include <cassert>

constexpr unsigned M = 1000000007;

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

        [[nodiscard]] constexpr Integer raise(long long power) const noexcept
        {
            if (power < 0) {
                assert(residue_ != 0);
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

            int64_t x = 1, y = 0, a = residue_, b = modulus;
            while (b != 0) {
                x = std::exchange(y, x - a / b * y);
                a = std::exchange(b, a % b);
            }
            assert(a == 1 && "inverse does not exist (residue is not coprime to modulus)");
            return x;
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

using integer = modular_arithmetic::Integer<M>;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m, unsigned k)
{
    if (k == 1 || k > n)
        return answer(integer(m).raise(n));

    if (k == n)
        return answer(integer(m).raise((n + 1) / 2));

    answer(k % 2 == 0 ? m : m * m);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, m, k;
    std::cin >> n >> m >> k;

    solve(n, m, k);

    return 0;
}
