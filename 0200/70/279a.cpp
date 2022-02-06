#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(int x, int y)
{
    if (x == 0 && y == 0)
        return answer(0);

    constexpr int dx[4] = { 1, 0, -1, 0 };
    constexpr int dy[4] = { 0, 1, 0, -1 };

    for (int cx = 0, cy = 0, i = 0; ; ++i) {
        for (int j = 0; j <= i / 2; ++j) {
            cx += dx[i % 4], cy += dy[i % 4];
            if (cx == x && cy == y)
                return answer(i);
        }
    }
}

int main()
{
    int x, y;
    std::cin >> x >> y;

    solve(x, y);

    return 0;
}
