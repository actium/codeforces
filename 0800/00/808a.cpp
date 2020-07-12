#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    unsigned x = n, y = 1;
    while (x > 9)
        x /= 10, y *= 10;

    answer(y * (x + 1) - n);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

