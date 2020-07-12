#include <iostream>
#include <iomanip>

void answer(unsigned h, unsigned m)
{
    std::cout << std::setfill('0') << std::setw(2) << h << ':' << std::setw(2) << m << '\n';
}

void solve(unsigned h, unsigned m, unsigned d)
{
    const unsigned t = (h * 60 + m + d) % 1440;

    answer(t / 60, t % 60);
}

int main()
{
    unsigned h, m;
    scanf("%02u:%02u", &h, &m);

    unsigned a;
    std::cin >> a;

    solve(h, m, a);

    return 0;
}

