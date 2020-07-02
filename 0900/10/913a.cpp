#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned m)
{
    if (n > 31)
        answer(m);
    else
        answer(m & ((1 << n) - 1));
}

int main()
{
    unsigned n;
    std::cin >> n;

    unsigned m;
    std::cin >> m;

    solve(n, m);

    return 0;
}

