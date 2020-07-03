#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n)
{
    const unsigned k = n / 7;
    const unsigned r = n % 7;

    answer(k * 2 + (r == 6), k * 2 + std::min(r, 2u));
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

