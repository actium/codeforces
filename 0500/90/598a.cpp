#include <iostream>

void answer(long long v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    long long sum = n * (n + 1ll) / 2;
    for (unsigned i = 1; i <= n; i <<= 1)
        sum -= 2 * i;

    answer(sum);
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

