#include <iostream>
#include <numeric>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned p)
{
    unsigned k = 0;
    for (unsigned x = 1; x < p; ++x) {
        if (std::gcd(x, p - 1) == 1)
            ++k;
    }

    answer(k);
}

int main()
{
    unsigned p;
    std::cin >> p;

    solve(p);

    return 0;
}
