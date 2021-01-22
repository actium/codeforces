#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

unsigned t(int y, int m, int d)
{
    const int a = (m - 14) / 12;
    const int b = y + 4800 + a;
    return 1461 * b / 4 + 367 * (m - 2 - a * 12) / 12 - (b + 100) / 100 * 3 / 4 + d - 32075;
}

void solve(unsigned y1, unsigned m1, unsigned d1, unsigned y2, unsigned m2, unsigned d2)
{
    answer(abs(t(y2, m2, d2) - t(y1, m1, d1)));
}

int main()
{
    unsigned y1, m1, d1;
    scanf("%4u:%02u:%02u", &y1, &m1, &d1);

    unsigned y2, m2, d2;
    scanf("%4u:%02u:%02u", &y2, &m2, &d2);

    solve(y1, m1, d1, y2, m2, d2);

    return 0;
}

