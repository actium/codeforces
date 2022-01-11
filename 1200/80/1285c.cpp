#include <iostream>

#include <numeric>

using integer = unsigned long long;

void answer(integer x, integer y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(integer x)
{
    integer y = x;
    for (integer a = 1; a * a <= x; ++a) {
        if (x % a == 0 && std::lcm(a, x / a) == x)
            y = a;
    }

    answer(y, x / y);
}

int main()
{
    integer x;
    std::cin >> x;

    solve(x);

    return 0;
}
