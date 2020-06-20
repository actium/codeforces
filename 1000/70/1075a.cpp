#include <iostream>

using integer = long long;

void answer(bool v)
{
    constexpr const char* s[2] = { "Black", "White" };
    std::cout << s[v] << '\n';
}

void solve(integer n, integer x, integer y)
{
    const integer d1 = std::max(x - 1, y - 1);
    const integer d2 = std::max(n - x, n - y);

    answer(d1 <= d2);
}

int main()
{
    integer n;
    std::cin >> n;

    integer x, y;
    std::cin >> x >> y;

    solve(n, x, y);

    return 0;
}

