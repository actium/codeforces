#include <iostream>

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void solve(unsigned a, unsigned b, unsigned c)
{
    const unsigned d = (a + b + c) % 2;

    answer(a % 2 == d, b % 2 == d, c % 2 == d);
}

void test_case()
{
    unsigned a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);
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
