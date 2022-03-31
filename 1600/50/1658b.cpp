#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    constexpr unsigned M = 998244353;

    if (n % 2 == 1)
        return answer(0);

    unsigned long long k = 1;
    for (unsigned i = 1; i <= n / 2; ++i)
        k = k * i * i % M;

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
