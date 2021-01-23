#include <iostream>

#include <cmath>

void answer(double x, double y)
{
    std::cout << std::fixed << x << '\n';
    std::cout << std::fixed << y << '\n';
}

void solve(int a, int b, int c)
{
    const int d = b * b - 4 * a * c;

    const double x1 = 0.5 * (-b + sqrt(d)) / a;
    const double x2 = 0.5 * (-b - sqrt(d)) / a;

    answer(std::max(x1, x2), std::min(x1, x2));
}

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);

    return 0;
}

