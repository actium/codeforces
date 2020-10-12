#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned k)
{
    unsigned r = k - 1;
    while (n % r != 0)
        --r;

    answer(n / r * k + r);
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

