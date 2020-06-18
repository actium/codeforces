#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n)
{
    if (n % 2 == 0)
        answer(8, n - 8);
    else
        answer(9, n - 9);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

