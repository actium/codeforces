#include <iostream>
#include <iomanip>

void answer(unsigned h, unsigned m)
{
    std::cout << std::setfill('0') << std::setw(2) << h << ':' << std::setw(2) << m << '\n';
}

void solve(unsigned sh, unsigned sm, unsigned th, unsigned tm)
{
    const unsigned t = (1440 + sh * 60 + sm - th * 60 - tm) % 1440;

    answer(t / 60, t % 60);
}

int main()
{
    unsigned sh, sm;
    scanf("%02u:%02u", &sh, &sm);

    unsigned th, tm;
    scanf("%02u:%02u", &th, &tm);

    solve(sh, sm, th, tm);

    return 0;
}

