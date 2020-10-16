#include <iostream>

void answer(int w, int x, int y, int z)
{
    std::cout << w << ' ' << x << ' ' << y << ' ' << z << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(int x1, int y1, int x2, int y2)
{
    const int dx = x2 - x1;
    const int dy = y2 - y1;

    if (dx == 0 || dy == 0)
        return answer(x1 + dy, y1 + dx, x2 + dy, y2 + dx);

    if (abs(dx) == abs(dy))
        return answer(x1, y2, x2, y1);

    no_answer();
}

int main()
{
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;

    solve(x1, y1, x2, y2);

    return 0;
}

