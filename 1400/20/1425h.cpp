#include <iostream>

const char* answer(bool v)
{
    constexpr const char* s[2] = { "Tidak", "Ya" };
    return s[v];
}

void solve(unsigned a, unsigned b, unsigned c, unsigned d)
{
    const bool e = ((a + b) % 2 == 0);

    std::cout
        << answer(!e && a + d > 0) << ' '
        << answer(!e && b + c > 0) << ' '
        << answer( e && b + c > 0) << ' '
        << answer( e && a + d > 0) << '\n';
}

void test_case()
{
    unsigned a, b, c, d;
    std::cin >> a >> b >> c >> d;

    solve(a, b, c, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

