#include <iostream>
#include <numeric>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned x, unsigned y, unsigned a, unsigned b)
{
    const unsigned g = std::lcm(x, y);

    answer(b / g - (a - 1) / g);
}

int main()
{
    unsigned x, y, a, b;
    std::cin >> x >> y >> a >> b;

    solve(x, y, a, b);

    return 0;
}

