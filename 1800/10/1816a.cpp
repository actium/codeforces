#include <iostream>

void solve(unsigned a, unsigned b)
{
    std::cout << 2 << '\n';
    std::cout << 1 << ' ' << b - 1 << '\n';
    std::cout << a << ' ' << b << '\n';
}

void test_case()
{
    unsigned a, b;
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
