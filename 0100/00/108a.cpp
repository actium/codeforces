#include <cstdio>

bool palindromic(unsigned t)
{
    const unsigned h = t / 60;
    const unsigned m = t % 60;

    return h / 10 == m % 10 && h % 10 == m / 10;
}

void answer(unsigned v)
{
    printf("%02u:%02u\n", v / 60, v % 60);
}

void solve(unsigned h, unsigned m)
{
    unsigned t = (h * 60 + m + 1) % 1440;
    while (!palindromic(t))
        t = (t + 1) % 1440;

    answer(t);
}

int main()
{
    unsigned h, m;
    scanf("%02u:%02u", &h, &m);

    solve(h, m);

    return 0;
}

