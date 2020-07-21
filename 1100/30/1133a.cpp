#include <cstdio>

void answer(unsigned t)
{
    printf("%02u:%02u\n", t / 60, t % 60);
}

void solve(unsigned h1, unsigned m1, unsigned h2, unsigned m2)
{
    const unsigned t1 = h1 * 60 + m1;
    const unsigned t2 = h2 * 60 + m2;

    answer((t1 + t2) / 2);
}

int main()
{
    unsigned h1, m1;
    scanf("%02u:%02u", &h1, &m1);

    unsigned h2, m2;
    scanf("%02u:%02u", &h2, &m2);

    solve(h1, m1, h2, m2);

    return 0;
}

