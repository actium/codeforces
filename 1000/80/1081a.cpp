#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned v)
{
    answer(v > 2 ? 1 : v);
}

int main()
{
    unsigned v;
    std::cin >> v;

    solve(v);

    return 0;
}

