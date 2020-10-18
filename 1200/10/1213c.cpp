#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n, integer m)
{
    const integer k = n / m;

    integer c = 0;
    for (unsigned i = 1; i <= 10; ++i) {
        const unsigned d = m * i % 10;
        c += k / 10 * d;
        c += d * (i <= k % 10);
    }

    answer(c);
}

void test_case()
{
    integer n, m;
    std::cin >> n >> m;

    solve(n, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

