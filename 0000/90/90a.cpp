#include <algorithm>
#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned r, unsigned g, unsigned b)
{
    const unsigned x = 30 + ((r + 1) / 2 - 1) * 3;
    const unsigned y = 31 + ((g + 1) / 2 - 1) * 3;
    const unsigned z = 32 + ((b + 1) / 2 - 1) * 3;

    answer(std::max({ x, y, z }));
}

int main()
{
    unsigned r, g, b;
    std::cin >> r >> g >> b;

    solve(r, g, b);

    return 0;
}

