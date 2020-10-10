#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n)
{
    constexpr integer m = 2 * 3 * 2 * 5 * 7 * 2 * 3;

    answer(n / m);
}

int main()
{
    integer n;
    std::cin >> n;

    solve(n);

    return 0;
}

