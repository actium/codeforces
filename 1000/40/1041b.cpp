#include <iostream>
#include <numeric>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer a, integer b, integer x, integer y)
{
    const integer r = std::gcd(x, y);
    const integer w = x / r;
    const integer h = y / r;

    answer(std::min(a / w, b / h));
}

int main()
{
    integer a, b, x, y;
    std::cin >> a >> b >> x >> y;

    solve(a, b, x, y);

    return 0;
}

