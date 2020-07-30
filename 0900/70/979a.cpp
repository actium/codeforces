#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n)
{
    if (n == 0)
        return answer(0);

    answer(++n % 2 == 0 ? n / 2 : n);
}

int main()
{
    integer n;
    std::cin >> n;

    solve(n);

    return 0;
}

