#include <iostream>

using integer = unsigned long long;

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

bool check(integer a, integer b, integer x)
{
    if (b == 0)
        return false;

    if (a >= x && (a - x) % b == 0)
        return true;

    return check(b, a % b, x);
}

void solve(integer a, integer b, integer x)
{
    answer(check(a, b, x));
}

void test_case()
{
    integer a, b, x;
    std::cin >> a >> b >> x;

    solve(a, b, x);
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
