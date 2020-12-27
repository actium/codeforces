#include <iostream>

void answer(double x, double y)
{
    std::cout << std::fixed << x << ' ' << y << '\n';
}

void solve(unsigned h, unsigned m)
{
    answer(30 * (h % 12 + m / 60.0), 6 * m);
}

int main()
{
    unsigned h, m;
    scanf("%2u:%2u", &h, &m);

    solve(h, m);

    return 0;
}

