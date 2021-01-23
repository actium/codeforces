#include <iostream>

using point_t = std::pair<int, int>;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

void answer(const char* v)
{
    std::cout << v << '\n';
}

void solve(const point_t& a, const point_t& b, const point_t& c)
{
    const long long dx1 = b.first - a.first, dx2 = c.first - a.first;
    const long long dy1 = b.second - a.second, dy2 = c.second - a.second;

    const long long cp = dy1 * dx2 - dx1 * dy2;
    if (cp == 0)
        return answer("TOWARDS");

    answer(cp > 0 ? "RIGHT" : "LEFT");
}

int main()
{
    point_t a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);

    return 0;
}

