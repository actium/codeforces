#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned a, unsigned b)
{
    const unsigned c = std::min(a, b);
    a -= c, b -= c;

    answer(c, (a + b) / 2);
}

int main()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}

