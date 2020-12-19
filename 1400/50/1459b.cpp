#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    int a = n * (n + 4) + 2;
    if (n % 2 == 1)
        a = -a;

    answer((3 * n * (n + 4) - a + 10) / 8);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

