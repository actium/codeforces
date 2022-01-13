#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>

void answer(double x)
{
    std::cout << std::fixed << x << '\n';
}

void solve(unsigned n)
{
    answer(1 / tan(M_PI / n));
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(2 * n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
