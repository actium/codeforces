#include <iostream>

void solve(unsigned n)
{
    for (unsigned i = 2; i <= n; ++i)
        std::cout << i << ' ';

    std::cout << 1 << '\n';
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

