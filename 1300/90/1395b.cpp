#include <iostream>

void step(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned w, unsigned h, unsigned sx, unsigned sy)
{
    for (unsigned y = sy; y <= h; ++y)
        step(sx, y);

    for (unsigned y = sy-1; y >= 1; --y)
        step(sx, y);

    for (unsigned x = 1, y = 0; x <= w; ++x) {
        if (x == sx)
            continue;

        if (y == 0) {
            for (y = 1; y <= h; ++y)
                step(x, y);
        } else {
            for (y = h; y >= 1; --y)
                step(x, y);
        }
    }
}

int main()
{
    unsigned w, h, sx, sy;
    std::cin >> w >> h >> sx >> sy;

    solve(w, h, sx, sy);

    return 0;
}

