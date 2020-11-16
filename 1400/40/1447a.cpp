#include <iostream>

void solve(unsigned n)
{
    std::cout << n-1 << '\n';

    for (unsigned i = 2; i < n; ++i)
        std::cout << i << ' ';

    std::cout << n << '\n';
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

