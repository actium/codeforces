#include <iostream>

void solve(unsigned n)
{
    std::cout << n / 2 + n % 2 << '\n';
    for (unsigned i = 1, j = 3 * n; i < j; i += 3, j -= 3) {
        std::cout << i << ' ' << j << '\n';
    }
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
