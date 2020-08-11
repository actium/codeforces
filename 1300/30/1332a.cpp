#include <iostream>

using position_t = std::pair<int, int>;

std::istream& operator >>(std::istream& input, position_t& v)
{
    return input >> v.first >> v.second;
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned a, unsigned b, unsigned c, unsigned d, const position_t& p0, const position_t& p1, const position_t& p2)
{
    const unsigned dx = p2.first - p1.first;
    if (dx == 0 && a + b > 0)
        return answer(false);

    const unsigned dy = p2.second - p1.second;
    if (dy == 0 && c + d > 0)
        return answer(false);

    const position_t p = std::make_pair(p0.first - a + b, p0.second - c + d);
    answer(p.first >= p1.first && p.first <= p2.first && p.second >= p1.second && p.second <= p2.second);
}

void test_case()
{
    unsigned a, b, c, d;
    std::cin >> a >> b >> c >> d;

    position_t p0, p1, p2;
    std::cin >> p0 >> p1 >> p2;

    solve(a, b, c, d, p0, p1, p2);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

