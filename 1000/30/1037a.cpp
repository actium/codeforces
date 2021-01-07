#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    answer(32 - __builtin_clz(n));
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

