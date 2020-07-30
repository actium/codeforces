#include <iostream>

using integer = unsigned long long;

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(integer x)
{
    const integer k = x / 14;
    const integer r = x % 14;

    answer(k > 0 && r > 0 && r < 7);
}

void test_case()
{
    integer x;
    std::cin >> x;

    solve(x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

