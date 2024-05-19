#include <iostream>

#include <cmath>

using integer = long long;
using point_t = std::pair<integer, integer>;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

void answer(double x, double y, double z)
{
    std::cout << std::fixed << x << ' ' << y << ' ' << z << '\n';
}

void solve(const point_t& s, const point_t& t, integer r)
{
    integer dx = t.first - s.first, dy = t.second - s.second;
    if (dx * dx + dy * dy >= r * r)
        return answer(s.first, s.second, r);

    const double d = hypot(dx, dy);
    if (d == 0)
        return answer(s.first + r / 2.0, s.second, r / 2.0);

    const double x = s.first - dx * r / d, y = s.second - dy * r / d;
    answer((x + t.first) / 2, (y + t.second) / 2, (d + r) / 2);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer r;
    std::cin >> r;

    point_t s, t;
    std::cin >> s >> t;

    solve(s, t, r);

    return 0;
}
