#include <iostream>

constexpr unsigned M = 1000000007;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned long long n)
{
    answer(n * (n + 1) % M * (4 * n - 1) % M * (2022 / 6) % M);
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
