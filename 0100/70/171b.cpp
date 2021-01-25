#include <iostream>

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(unsigned a)
{
    answer(6ull * a * (a - 1) + 1);
}

int main()
{
    unsigned a;
    std::cin >> a;

    solve(a);

    return 0;
}

