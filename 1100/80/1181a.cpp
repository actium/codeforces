#include <iostream>

using integer = unsigned long long;

void answer(integer x, integer y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(integer x, integer y, integer z)
{
    const integer a = x % z;
    const integer b = y % z;

    answer((x + y) / z, a + b < z ? 0 : z - std::max(a, b));
}

int main()
{
    integer x, y, z;
    std::cin >> x >> y >> z;

    solve(x, y, z);

    return 0;
}

