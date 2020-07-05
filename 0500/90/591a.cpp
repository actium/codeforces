#include <iostream>

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

void solve(unsigned d, unsigned p, unsigned q)
{
    answer(p * d / double(p + q));
}

int main()
{
    unsigned d;
    std::cin >> d;

    unsigned p, q;
    std::cin >> p >> q;

    solve(d, p, q);

    return 0;
}

