#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

unsigned dp(unsigned p, unsigned n)
{
    if (n == 0)
        return p;

    unsigned x = dp(n % 10, n / 10);
    if (n > 9)
        x = std::max(x, dp(9, (n - 9) / 10));

    return p * x;
}

void solve(unsigned n)
{
    answer(dp(1, n));
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

