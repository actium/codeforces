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

void solve(const point_t& p1, const point_t& p2, const point_t& p3)
{
    if (p1.second == p2.second && p3.second < p1.second)
        return answer(std::abs(p1.first - p2.first));

    if (p2.second == p3.second && p1.second < p2.second)
        return answer(std::abs(p2.first - p3.first));

    if (p3.second == p1.second && p2.second < p3.second)
        return answer(std::abs(p3.first - p1.first));

    answer(0);
}

void test_case()
{
    point_t p1, p2, p3;
    std::cin >> p1 >> p2 >> p3;

    solve(p1, p2, p3);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
