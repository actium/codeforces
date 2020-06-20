#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned a)
{
    answer(a % 2);
}

int main()
{
    unsigned a;
    std::cin >> a;

    solve(a);

    return 0;
}

