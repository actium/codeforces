#include <iostream>

using integer = unsigned long long;

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(integer a, integer b, integer c)
{
    const integer s = a + b + c;
    const integer d = s / 9;

    answer(s % 9 == 0 && a >= d && b >= d && c >= d);
}

void test_case()
{
    integer a, b, c;
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

