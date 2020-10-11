#include <iostream>

void solve(unsigned n)
{
    std::cout << 2 << '\n';

    if (n == 2) {
        std::cout << 1 << ' ' << 2 <<'\n';
        return;
    }

    std::cout << n - 2 << ' ' << n << '\n';
    std::cout << n - 1 << ' ' << n - 1 << '\n';

    for (unsigned i = 3; i < n; ++i)
        std::cout << n - i << ' ' << n - i + 2 << '\n';
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

