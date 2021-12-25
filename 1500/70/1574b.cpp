#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned a, unsigned b, unsigned c, unsigned m)
{
    if (a > b) std::swap(a, b);
    if (b > c) std::swap(b, c);
    if (a > b) std::swap(a, b);

    answer(c - 1 <= m + a + b && m + 3 <= a + b + c);
}

void test_case()
{
    unsigned a, b, c, m;
    std::cin >> a >> b >> c >> m;

    solve(a, b, c, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
