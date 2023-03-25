#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "-", "+" };
    std::cout << s[v] << '\n';
}

void solve(int a, int b, int c)
{
    answer(a + b == c);
}

void test_case()
{
    int a, b, c;
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
