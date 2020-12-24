#include <iostream>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

using position_t = std::pair<int, int>;

void solve(const position_t& p1, const position_t& p2, unsigned x, unsigned y)
{
    const int dx = abs(p2.first - p1.first);
    if (dx % x != 0)
        return answer(false);

    const int dy = abs(p2.second - p1.second);
    if (dy % y != 0)
        return answer(false);

    answer(dx / x % 2 == dy / y % 2);
}

int main()
{
    position_t p1, p2;
    std::cin >> p1 >> p2;

    unsigned x, y;
    std::cin >> x >> y;

    solve(p1, p2, x, y);

    return 0;
}

