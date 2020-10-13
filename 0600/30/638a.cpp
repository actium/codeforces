#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned a)
{
    if (a % 2 == 0)
        a = n - a + 1;

    answer(1 + a / 2);
}

int main()
{
    unsigned n, a;
    std::cin >> n >> a;

    solve(n, a);

    return 0;
}

