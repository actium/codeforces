#include <iostream>

using point_t = std::pair<int, int>;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned r, const point_t& s, const point_t& t)
{
    using integer = unsigned long long;

    const integer dx = std::abs(t.first - s.first), dy = std::abs(t.second - s.second);

    integer k = 0;
    for (const integer x = dx * dx + dy * dy; k * k * 4 * r * r < x; ++k);

    answer(k);
}

int main()
{
    unsigned r;
    std::cin >> r;

    point_t s, t;
    std::cin >> s >> t;

    solve(r, s, t);

    return 0;
}
