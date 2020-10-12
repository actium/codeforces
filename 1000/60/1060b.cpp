#include <iostream>

using integer = unsigned long long;

void answer(unsigned v)
{
    std::cout << v << '\n';
}

unsigned sum(integer n)
{
    unsigned s = 0;
    while (n != 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

void solve(integer n)
{
    integer a = 0;
    for (integer m = n; a * 10 + 9 <= n; m /= 10)
        a = a * 10 + 9;

    answer(sum(a) + sum(n - a));
}

int main()
{
    integer n;
    std::cin >> n;

    solve(n);

    return 0;
}

