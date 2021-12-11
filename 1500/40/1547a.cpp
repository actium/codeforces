#include <iostream>

using point_t = std::pair<int, int>;

std::istream& operator >>(std::istream& input, point_t& v)
{
    return input >> v.first >> v.second;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const point_t& a, const point_t& b, const point_t& f)
{
    const auto dx = abs(b.first - a.first);
    const auto dy = abs(b.second - a.second);

    const auto is_between = [](int x, int a, int b) {
        return x > std::min(a, b) && x < std::max(a, b);
    };

    if (dx == 0 && a.first == f.first && is_between(f.second, a.second, b.second))
            return answer(dx + dy + 2);

    if (dy == 0 && a.second == f.second && is_between(f.first, a.first, b.first))
        return answer(dx + dy + 2);

    answer(dx + dy);
}

void test_case()
{
    point_t a, b, f;
    std::cin >> a >> b >> f;

    solve(a, b, f);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
