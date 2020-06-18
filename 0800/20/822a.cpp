#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned a, unsigned b)
{
    unsigned gcd = 1;
    for (size_t i = 2; i <= std::min(a, b); ++i)
        gcd *= i;

    answer(gcd);
}

int main()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

