#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned k)
{
    constexpr unsigned M = 1000000007;

    unsigned r = 1;
    for (unsigned b = n; k != 0; k /= 2) {
        if (k & 1)
            r = 1ull * r * b % M;

        b = 1ull * b * b % M;
    }

    answer(r);
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
