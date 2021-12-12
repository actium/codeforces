#include <iostream>
#include <numeric>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned k)
{
    answer(100 / std::gcd(k, 100));
}

void test_case()
{
    unsigned k;
    std::cin >> k;

    solve(k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
