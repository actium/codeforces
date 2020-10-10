#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    answer((n - 2) * (n - 2));
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

