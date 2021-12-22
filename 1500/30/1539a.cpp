#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned x, unsigned t)
{
    const integer k = std::min(t / x, n);

    // (n - k) * k + (k - 1) * k / 2
    answer(k * (2 * n - k - 1) / 2);
}

void test_case()
{
    unsigned n, x, t;
    std::cin >> n >> x >> t;

    solve(n, x, t);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
