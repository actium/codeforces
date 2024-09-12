#include <iostream>

#include <cmath>

void answer(double x)
{
    std::cout << std::fixed << x << '\n';
}

void solve(double x)
{
    answer(std::log2(x));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    double x;
    std::cin >> x;

    solve(x);

    return 0;
}
