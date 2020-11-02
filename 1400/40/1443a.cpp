#include <iostream>

void solve(unsigned n)
{
    constexpr const char d[2] = { '\n', ' ' };

    for (unsigned x = 4 * n; n-- > 0; x -= 2)
        std::cout << x << d[n!=0];
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

