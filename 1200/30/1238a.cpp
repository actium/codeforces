#include <iostream>

using integer = unsigned long long;

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(integer x, integer y)
{
    const integer d = x - y;

    answer(d > 1);
}

void test_case()
{
    integer x, y;
    std::cin >> x >> y;

    solve(x, y);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

