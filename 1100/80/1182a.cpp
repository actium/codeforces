#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    answer(n % 2 == 0 ? 1 << n/2 : 0);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

