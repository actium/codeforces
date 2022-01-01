#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned h, unsigned p)
{
    integer k = 0;

    integer n = (1ull << h) - 1, r = 1;
    while (r <= n && r < p) {
        n -= r;
        r *= 2;
        ++k;
    }

    const integer q = n / p;
    k += q;
    n -= q * p;

    if (n != 0)
        ++k;

    answer(k);
}

void test_case()
{
    unsigned h, p;
    std::cin >> h >> p;

    solve(h, p);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
