#include <iostream>
#include <utility>
#include <vector>

#include <cassert>

struct Segment {
    unsigned l;
    unsigned r;
    unsigned p;
    unsigned q;
};

std::istream& operator >>(std::istream& input, Segment& s)
{
    return input >> s.l >> s.r >> s.p >> s.q;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

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

        // note: if modulus is a prime number, raise(modulus-2) also returns the inverse
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

using integer = modular_arithmetic::Integer<998244353>;

void solve(const std::vector<Segment>& s, unsigned m)
{
    const size_t n = s.size();

    std::vector<std::vector<size_t>> q(1+m);
    for (size_t i = 0; i < n; ++i)
        q[s[i].r].push_back(i);

    std::vector<integer> dp(1 + m);
    dp[0] = 1;
    for (size_t i = 0; i < n; ++i) {
        const integer r = integer(s[i].p) / s[i].q;
        dp[0] *= 1 - r;
    }

    for (unsigned t = 1; t <= m; ++t) {
        for (const size_t i : q[t]) {
            const integer r = integer(s[i].p) / s[i].q;
            dp[t] += dp[s[i].l-1] * r / (1 - r);
        }
    }

    answer(dp[m]);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    std::vector<Segment> s(n);
    std::cin >> s;

    solve(s, m);

    return 0;
}
