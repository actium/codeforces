#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned x, unsigned y)
{
    const unsigned r = (y * n + 99) / 100;

    answer(r > x ? r - x : 0);
}

int main()
{
    unsigned n, x, y;
    std::cin >> n >> x >> y;

    solve(n, x, y);

    return 0;
}

