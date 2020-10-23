#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n)
{
    const unsigned p = n % 2;
    if (p == 1) {
        integer x = 3;
        while (x * x <= n && n % x != 0)
            x += 2;

        if (n % x != 0)
            x = n;

        n -= x;
    }

    answer(p + n / 2);
}

int main()
{
    integer n;
    std::cin >> n;

    solve(n);

    return 0;
}

