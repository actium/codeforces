#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

bool check(unsigned n, unsigned m)
{
    if (n < m)
        return false;

    if (n == m)
        return true;

    if (n % 3 != 0)
        return false;

    return check(2 * n / 3, m) || check(n / 3, m);
}

void solve(unsigned n, unsigned m)
{
    answer(check(n, m));
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
