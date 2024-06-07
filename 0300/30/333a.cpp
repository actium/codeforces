#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer n)
{
    integer b = 3;
    while (n % b == 0)
        b *= 3;

    answer(n / b + 1);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer n;
    std::cin >> n;

    solve(n);

    return 0;
}
