#include <iostream>

#include <cmath>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n)
{
    size_t x = sqrt(n);
    while (n / x * x != n)
        ++x;

    answer(2 * x + 2 * (n / x));
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}

