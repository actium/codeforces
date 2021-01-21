#include <iostream>

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void solve(unsigned n, unsigned a)
{
    answer(2, 1, std::min<unsigned>(n, 3 + int(a * n - 90) / 180));
}

int main()
{
    unsigned n, a;
    std::cin >> n >> a;

    solve(n, a);

    return 0;
}

