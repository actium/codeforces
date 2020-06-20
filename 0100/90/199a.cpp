#include <iostream>

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';;
}

void solve(unsigned n)
{
    answer(0, 0, n);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

