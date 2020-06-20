#include <iostream>

using integer = long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer x1, integer y1, integer x2, integer y2)
{
    const integer dx = abs(x1 - x2);
    const integer dy = abs(y1 - y2);

    answer(std::max(dx, dy));
}

int main()
{
    integer x1, y1;
    std::cin >> x1 >> y1;

    integer x2, y2;
    std::cin >> x2 >> y2;

    solve(x1, y1, x2, y2);

    return 0;
}

