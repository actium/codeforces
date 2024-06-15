#include <iostream>
#include <vector>

#include <cmath>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

namespace geometry {

    template <typename T>
    struct Vector {
        T dx = 0;
        T dy = 0;

        constexpr Vector() noexcept = default;

        constexpr Vector(T dx, T dy) noexcept
            : dx(dx)
            , dy(dy)
        {}

        constexpr Vector& operator *=(T scale_factor) noexcept
        {
            dx *= scale_factor;
            dy *= scale_factor;
            return *this;
        }

        constexpr Vector& operator /=(T scale_factor) noexcept
        {
            dx /= scale_factor;
            dy /= scale_factor;
            return *this;
        }

    }; // struct Vector<T>

    template <typename T>
    constexpr inline Vector<T> operator -(const Vector<T>& v) noexcept
    {
        return Vector<T>(-v.dx, -v.dy);
    }

    template <typename T>
    constexpr inline Vector<T> operator *(Vector<T>& lhs, T rhs) noexcept
    {
        return lhs *= rhs;
    }

    template <typename T>
    constexpr inline Vector<T> operator /(Vector<T>& lhs, T rhs) noexcept
    {
        return lhs /= rhs;
    }

    template <typename T>
    constexpr inline bool operator ==(const Vector<T>& lhs, const Vector<T>& rhs) noexcept
    {
        return lhs.dx == rhs.dx && lhs.dy == rhs.dy;
    }

    template <typename T>
    constexpr inline bool operator !=(const Vector<T>& lhs, const Vector<T>& rhs) noexcept
    {
        return lhs.dx != rhs.dx || lhs.dy != rhs.dy;
    }

    template <typename T>
    constexpr inline T dot_product(const Vector<T>& lhs, const Vector<T>& rhs) noexcept
    {
        return lhs.dx * rhs.dx + lhs.dy * rhs.dy;
    }

    template <typename T>
    constexpr inline T cross_product(const Vector<T>& lhs, const Vector<T>& rhs) noexcept
    {
        return lhs.dx * rhs.dy - lhs.dy * rhs.dx;
    }

    template <typename T>
    constexpr inline T length(const Vector<T>& v) noexcept
    {
        return std::sqrt(dot_product(v, v));
    }

    // returns true if |lhs| < |rhs|, false otherwise
    template <typename T>
    constexpr inline bool operator <(const Vector<T>& lhs, const Vector<T>& rhs) noexcept
    {
        return dot_product(lhs, lhs) < dot_product(rhs, rhs);
    }

    // returns true if |lhs| > |rhs|, false otherwise
    template <typename T>
    constexpr inline bool operator >(const Vector<T>& lhs, const Vector<T>& rhs) noexcept
    {
        return dot_product(lhs, lhs) > dot_product(rhs, rhs);
    }

    template <typename T>
    struct Point {
        T x = 0;
        T y = 0;

        constexpr Point() noexcept = default;

        constexpr Point(T x, T y) noexcept
            : x(x)
            , y(y)
        {}

        constexpr Point& operator +=(const Vector<T>& rhs) noexcept
        {
            x += rhs.dx;
            y += rhs.dy;
            return *this;
        }

        constexpr Point& operator -=(const Vector<T>& rhs) noexcept
        {
            x -= rhs.dx;
            y -= rhs.dy;
            return *this;
        }

    }; // struct Point<T>

    template <typename T>
    constexpr inline Vector<T> operator -(const Point<T>& lhs, const Point<T>& rhs) noexcept
    {
        return Vector<T>(lhs.x - rhs.x, lhs.y - rhs.y);
    }

    template <typename T>
    constexpr inline Point<T> operator +(const Point<T>& lhs, const Vector<T>& rhs) noexcept
    {
        return Point<T>(lhs.x + rhs.dx, lhs.y + rhs.dy);
    }

    template <typename T>
    constexpr inline Point<T> operator -(const Point<T>& lhs, const Vector<T>& rhs) noexcept
    {
        return Point<T>(lhs.x - rhs.dx, lhs.y - rhs.dy);
    }

} // namespace geometry

using point = geometry::Point<long long>;

bool test_collinearity(const point& o, const point& p, const point& q)
{
    return cross_product(p - o, q - o) == 0;
}

bool test_collinearity(const std::vector<point>& ps)
{
    const size_t n = ps.size();

    for (size_t i = 2; i < n; ++i) {
        if (!test_collinearity(ps[0], ps[i-1], ps[i]))
            return false;
    }
    return true;
}

void solve(const std::vector<int>& y)
{
    const size_t n = y.size();

    const point x = { 1, y[0] };

    std::vector<point> ps(n - 1);
    for (size_t i = 1; i < n; ++i)
        ps[i-1] = point(i + 1, y[i]);

    for (const point& p : ps) {
        std::vector<point> qs;
        for (const point& q : ps) {
            if (!test_collinearity(x, p, q))
                qs.push_back(q);
        }

        if (qs.empty())
            continue;

        if (qs.size() == 1)
            return answer(true);

        const auto d = x - qs[0];
        if (test_collinearity(qs[0] + d, qs[1] + d, p) && test_collinearity(qs))
            return answer(true);
    }

    answer(!test_collinearity(x, ps[0], ps[1]) && test_collinearity(ps));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t n;
    std::cin >> n;

    std::vector<int> y(n);
    std::cin >> y;

    solve(y);

    return 0;
}
