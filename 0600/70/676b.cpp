#include <iostream>
#include <numeric>
#include <vector>

class RationalNumber {
    using integer = unsigned long long;

public:
    constexpr RationalNumber() noexcept
        : RationalNumber(0)
    {}

    constexpr RationalNumber(unsigned numerator) noexcept
        : RationalNumber(numerator, 1)
    {}

    constexpr RationalNumber(unsigned numerator, unsigned denominator) noexcept
        : numerator_(numerator)
        , denominator_(denominator)
    {
        simplify();
    }

    constexpr RationalNumber& operator +=(const RationalNumber& rhs) noexcept
    {
        numerator_ = numerator_ * rhs.denominator_ + rhs.numerator_ * denominator_;
        denominator_ *= rhs.denominator_;
        simplify();
        return *this;
    }

    constexpr RationalNumber& operator -=(const RationalNumber& rhs) noexcept
    {
        numerator_ = numerator_ * rhs.denominator_ - rhs.numerator_ * denominator_;
        denominator_ *= rhs.denominator_;
        simplify();
        return *this;
    }

    constexpr RationalNumber& operator /=(const RationalNumber& rhs) noexcept
    {
        numerator_ *= rhs.denominator_;
        denominator_ *= rhs.numerator_;
        simplify();
        return *this;
    }

    bool operator >(const RationalNumber& rhs) const
    {
        return numerator_ * rhs.denominator_ > rhs.numerator_ * denominator_;
    }

    bool operator >=(const RationalNumber& rhs) const
    {
        return numerator_ * rhs.denominator_ >= rhs.numerator_ * denominator_;
    }

private:
    constexpr void simplify() noexcept
    {
        const unsigned d = std::gcd(numerator_, denominator_);
        numerator_ /= d;
        denominator_ /= d;
    }

private:
    integer numerator_;
    integer denominator_;

}; // class RationalNumber

constexpr RationalNumber operator -(const RationalNumber& lhs, const RationalNumber& rhs) noexcept
{
    return RationalNumber(lhs) -= rhs;
}

constexpr RationalNumber operator /(const RationalNumber& lhs, const RationalNumber& rhs) noexcept
{
    return RationalNumber(lhs) /= rhs;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned t)
{
    std::vector<std::vector<RationalNumber>> v(n + 1);
    for (size_t i = 0; i <= n; ++i)
        v[i].resize(i + 1);

    v[0][0] = t;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j <= i; ++j) {
            if (v[i][j] > 1) {
                const RationalNumber d = v[i][j] - 1;
                v[i+1][j] += d / 2;
                v[i+1][j+1] += d / 2;
            }
        }
    }

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j <= i; ++j)
            k += (v[i][j] >= 1);
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, t;
    std::cin >> n >> t;

    solve(n, t);

    return 0;
}
