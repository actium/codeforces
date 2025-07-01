#include <iostream>

using point_t = std::pair<int, int>;

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

void solve(unsigned, unsigned, unsigned a, unsigned b, const point_t& p1, const point_t& p2)
{
    const unsigned dx = std::abs(p1.first - p2.first), dy = std::abs(p1.second - p2.second);

    if (dx == 0)
        return answer(dy % b == 0);

    if (dy == 0)
        return answer(dx % a == 0);

    answer(dx % a == 0 || dy %  b == 0);
}

void test_case()
{
    unsigned w, h, a, b;
    std::cin >> w >> h >> a >> b;

    point_t p1, p2;
    std::cin >> p1 >> p2;

    solve(w, h, a, b, p1, p2);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
