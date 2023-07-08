#include <iostream>

using point_t = std::pair<unsigned, unsigned>;

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const point_t& a, const point_t& b, const point_t& c)
{
    unsigned dx = 0;
    if (b.first > a.first && c.first > a.first)
        dx = std::max(dx, std::min(b.first, c.first) - a.first);

    if (b.first < a.first && c.first < a.first)
        dx = std::max(dx, a.first - std::max(b.first, c.first));

    unsigned dy = 0;
    if (b.second > a.second && c.second > a.second)
        dy = std::max(dy, std::min(b.second, c.second) - a.second);

    if (b.second < a.second && c.second < a.second)
        dy = std::max(dy, a.second - std::max(b.second, c.second));

    answer(1 + dx + dy);
}

void test_case()
{
    point_t a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);
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
