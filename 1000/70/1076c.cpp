#include <iostream>

#include <cmath>

void no_answer()
{
    std::cout << "N" << '\n';
}

void answer(double x, double y)
{
    std::cout << "Y" << std::fixed << ' ' << x << ' ' << y << '\n';
}

void solve(unsigned d)
{
    if (d == 0)
        return answer(0, 0);

    if (d < 4)
        return no_answer();

    const double q = sqrt(d * (d - 4));

    answer((d + q) / 2, (d - q) / 2);
}

void test_case()
{
    unsigned d;
    std::cin >> d;

    solve(d);
}

int main()
{
    std::cout.precision(9);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

