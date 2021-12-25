#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned k)
{
    constexpr unsigned M = 1000000007;

    unsigned long long b = 1, x = 0;
    for (size_t i = 0; i < 31; ++i) {
        if (k & 1 << i)
            x = (x + b) % M;

        b = b * n % M;
    }

    answer(x);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
