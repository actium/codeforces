#include <iostream>

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(unsigned long long k, unsigned x)
{
    answer(x + (k - 1) * 9);
}

void test_case()
{
    unsigned long long k;
    std::cin >> k;

    unsigned x;
    std::cin >> x;

    solve(k, x);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

