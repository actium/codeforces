#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned l, unsigned r)
{
    answer(r != l ? 2 : r);
}

int main()
{
    unsigned l, r;
    std::cin >> l >> r;

    solve(l, r);

    return 0;
}

