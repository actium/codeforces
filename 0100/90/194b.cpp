#include <iostream>

#include <numeric>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    const unsigned d = std::gcd(4 * n, n + 1);

    answer(4 * n / d + 1);
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

