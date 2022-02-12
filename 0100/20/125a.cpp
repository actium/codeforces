#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n)
{
    const unsigned d = (n + 1) / 3, p = d / 12;

    answer(p, d - p * 12);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
