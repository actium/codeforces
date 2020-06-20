#include <iostream>

using integer = long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer a, integer b, integer x, integer y, integer z)
{
    answer(std::max(0ll, 2 * x + y - a) + std::max(0ll, 3 * z + y - b));
}

int main()
{
    integer a, b;
    std::cin >> a >> b;

    integer x, y, z;
    std::cin >> x >> y >> z;

    solve(a, b, x, y, z);

    return 0;
}

