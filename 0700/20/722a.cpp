#include <iostream>

void answer(unsigned x, unsigned y)
{
    printf("%02u:%02u\n", x, y);
}

void solve(unsigned t, unsigned h, unsigned m)
{
    if (t == 12 && h > 12 || h > 23)
        h %= 10;

    if (t == 12 && h == 0)
        h = 10;

    if (m > 59)
        m %= 10;

    answer(h, m);
}

int main()
{
    unsigned t;
    scanf("%u", &t);

    unsigned h, m;
    scanf("%2u:%2u", &h, &m);

    solve(t, h, m);

    return 0;
}

