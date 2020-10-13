#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(int x1, int y1, int x2, int y2)
{
    const unsigned dx = abs(x1 - x2) + 1 + (x1 == x2);
    const unsigned dy = abs(y1 - y2) + 1 + (y1 == y2);

    answer(2 * (dx + dy));
}

int main()
{
    int x1, y1;
    std::cin >> x1 >> y1;

    int x2, y2;
    std::cin >> x2 >> y2;

    solve(x1, y1, x2, y2);

    return 0;
}

