#include <iostream>

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned m)
{
    const unsigned x = n / 5;
    const unsigned x1 = x + (n % 5 >= 1);
    const unsigned x2 = x + (n % 5 >= 2);
    const unsigned x3 = x + (n % 5 >= 3);
    const unsigned x4 = x + (n % 5 >= 4);

    const unsigned y = m / 5;
    const unsigned y1 = y + (m % 5 >= 1);
    const unsigned y2 = y + (m % 5 >= 2);
    const unsigned y3 = y + (m % 5 >= 3);
    const unsigned y4 = y + (m % 5 >= 4);

    answer(1ull * x * y + 1ull * x1 * y4 + 1ull * x2 * y3 + 1ull * x3 * y2 + 1ull * x4 * y1);
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

