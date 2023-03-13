#include <iostream>

constexpr unsigned M = 1000000007;

unsigned q[1 + 100000];

void initialize()
{
    q[0] = 1;
    for (unsigned i = 1; i <= 100000; ++i)
        q[i] = 1ull * q[i-1] * i % M;

    for (unsigned i = 100000; i > 0; --i)
        q[i] = 1ull * q[i] * (i - 1) * i % M;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    answer(q[n]);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
