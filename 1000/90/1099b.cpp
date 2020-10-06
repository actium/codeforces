#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    unsigned a = 1;
    while (a * a < n)
        ++a;

    const unsigned b = (n + a - 1) / a;

    answer(a + b);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

