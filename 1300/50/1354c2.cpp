#include <iostream>

#define _USE_MATH_DEFINES
#include <cmath>

void answer(double x)
{
    std::cout << std::fixed << x << '\n';
}

void solve(unsigned n)
{
    const double a = M_PI / n;

    answer(cos(a / 2) / sin(a));
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
