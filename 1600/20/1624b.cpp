#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned a, unsigned b, unsigned c)
{
    if (2 * b > a && (2 * b - a) % c == 0)
        return answer(true);

    if (2 * b > c && (2 * b - c) % a == 0)
        return answer(true);

    answer((a + c) % (2 * b) == 0);
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
