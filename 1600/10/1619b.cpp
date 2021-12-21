#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    using integer = unsigned long long;

    unsigned k = 0;

    for (integer x = 1; x * x <= n; ++x)
        ++k;

    for (integer x = 1; x * x * x <= n; ++x)
        ++k;

    for (integer x = 1; x * x * x * x * x * x <= n; ++x)
        --k;

    answer(k);
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
