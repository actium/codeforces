#include <iostream>

using point_t = std::pair<unsigned, unsigned>;

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

void solve(const point_t& a, const point_t& b, const point_t& c)
{
    if (a.first != b.first && a.first != c.first && b.first != c.first)
        return answer(true);

    if (a.second != b.second && a.second != c.second && b.second != c.second)
        return answer(true);

    answer(false);
}

void test_case()
{
    point_t a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
