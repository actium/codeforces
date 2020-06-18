#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(size_t a, size_t b, size_t c, size_t n)
{
    const size_t m = a + b + c + n;
    if (m % 3 != 0)
        return answer(false);

    const size_t k = m / 3;
    answer(k >= a && k >= b && k >= c);
}

void test_case()
{
    size_t a, b, c, n;
    std::cin >> a >> b >> c >> n;

    solve(a, b, c, n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

