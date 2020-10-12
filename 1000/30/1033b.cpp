#include <iostream>

using integer = unsigned long long;

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

bool check(integer n)
{
    if (n < 2 || n % 2 == 0)
        return false;

    for (integer x = 3; x * x <= n; x += 2) {
        if (n % x == 0)
            return false;
    }

    return true;
}

void solve(integer a, integer b)
{
    answer(a - b == 1 && check(a + b));
}

void test_case()
{
    integer a, b;
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

