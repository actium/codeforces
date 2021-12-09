#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    unsigned k = 0;
    for (unsigned b = 9, x = 1; b < 1000000000; b = b * 10 + 9, x = x * 10 + 1)
        k += std::min(n, b) / x;

    answer(k);
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
