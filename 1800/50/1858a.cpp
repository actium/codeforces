#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "First", "Second" };
    std::cout << s[v] << '\n';
}

void solve(unsigned a, unsigned b, unsigned c)
{
    answer(b >= a + c % 2);
}

void test_case()
{
    unsigned a, b, c;
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