#include <iostream>

#define M_PI        3.14159265358979323846

void no_answer()
{
    std::cout << "NO" << '\n';
}

void answer(double v)
{
    std::cout << "YES" << '\n';

    std::cout << std::fixed << v << '\n';
}

void solve(unsigned d, unsigned h, unsigned v, unsigned e)
{
    const double S = M_PI * d * d / 4;

    const double u = v / S;
    if (u > e)
        answer(h / (u - e));
    else
        no_answer();
}

int main()
{
    unsigned d, h, v, e;
    std::cin >> d >> h >> v >> e;

    solve(d, h, v, e);

    return 0;
}

