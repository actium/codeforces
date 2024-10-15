#include <iomanip>
#include <iostream>

void answer(double x)
{
    std::cout << std::fixed << std::setprecision(10) << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned a, unsigned b)
{
    if (a < b)
        return no_answer();

    const unsigned d = (a + b) / b;

    answer(double(a + b) / (d - d % 2));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
