#include <iostream>

int sign(int v)
{
    return v < 0 ? -1 : 1;
}

void answer(int x1, int y1, int x2, int y2)
{
    std::cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
}

void solve(int x, int y)
{
    int x1 = 0;
    int y1 = y + abs(x) * sign(y);
    int x2 = x + abs(y) * sign(x);
    int y2 = 0;

    if (x2 < x1) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    answer(x1, y1, x2, y2);
}

int main()
{
    int x, y;
    std::cin >> x >> y;

    solve(x, y);

    return 0;
}

