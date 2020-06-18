#include <iostream>

using integer = long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n)
{
    const int sign_factor = (n % 2 == 0 ? 1 : -1);
    answer(sign_factor * (n + 1) / 2);
}

int main()
{
    integer n;
    std::cin >> n;

    solve(n);

    return 0;
}

