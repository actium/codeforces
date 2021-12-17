#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    constexpr unsigned M = 1000000007;

    unsigned long long k = 1;
    for (unsigned i = 2; i <= 2 * n; ++i)
        k = (k * i) % (2 * M);

    answer(k / 2 % 1000000007);
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
