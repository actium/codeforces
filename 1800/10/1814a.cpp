#include <iostream>

using integer = unsigned long long;

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(integer n, integer k)
{
    answer(n % 2 == 0 || k % 2 != 0);
}

void test_case()
{
    integer n, k;
    std::cin >> n >> k;

    solve(n, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
