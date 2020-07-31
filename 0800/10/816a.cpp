#include <iostream>

bool palindromic(unsigned t)
{
    const unsigned h = t / 60;
    const unsigned m = t % 60;

    return h / 10 == m % 10 && h % 10 == m / 10;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned h, unsigned m)
{
    unsigned k = 0;
    for (unsigned t = h * 60 + m; !palindromic(t); t = (t + 1) % 1440)
        ++k;

    answer(k);
}

int main()
{
    unsigned h, m;
    scanf("%02u:%02u", &h, &m);

    solve(h, m);

    return 0;
}

