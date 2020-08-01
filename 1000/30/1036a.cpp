#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n, integer k)
{
    answer((k + n - 1) / n);
}

int main()
{
    integer n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

