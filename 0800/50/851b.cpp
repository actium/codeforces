#include <iostream>

using point_t = std::pair<int, int>;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const point_t& a, const point_t& b, const point_t& c)
{
    using integer = long long;

    const integer dx1 = b.first - a.first, dy1 = b.second - a.second;
    const integer dx2 = b.first - c.first, dy2 = b.second - c.second;

    if (dx1 * dx1 + dy1 * dy1 != dx2 * dx2 + dy2 * dy2)
        return answer(false);

    const integer dx3 = 2 * b.first - (a.first + c.first);
    const integer dy3 = 2 * b.second - (a.second + c.second);

    answer(dx3 * dx3 + dy3 * dy3 != 0);
}

int main()
{
    point_t a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);

    return 0;
}
