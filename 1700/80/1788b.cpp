#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n)
{
    const unsigned m = n / 2;

    unsigned d = 0;
    for (unsigned x = m, p = 0; x % 10 == 9; x /= 10, ++p)
        d = d * 10 + 4 + p % 2;

    answer(m - d, n - m + d);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
