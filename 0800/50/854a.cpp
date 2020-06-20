#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n)
{
    unsigned b = n / 2 + 1;
    if (b % 2 == 0 && (n - b) % 2 == 0)
        ++b;

    answer(n - b, b);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

