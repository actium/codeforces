#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

using integer = unsigned long long;

void solve(integer n)
{
    answer(2 - n % 2);
}

int main()
{
    integer n;
    std::cin >> n;

    solve(n);

    return 0;
}

