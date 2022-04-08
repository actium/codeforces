#include <iostream>

void solve(unsigned n)
{
    std::cout << n-3 << ' ' << 1 << ' ' << 1 << ' ' << 1 << '\n';
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
