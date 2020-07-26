#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n, unsigned ax, unsigned ay, unsigned bx, unsigned by, unsigned cx, unsigned cy)
{
    if (bx < ax && ax < cx)
        return answer(false);

    if (bx > ax && ax > cx)
        return answer(false);

    if (by < ay && ay < cy)
        return answer(false);

    if (by > ay && ay > cy)
        return answer(false);

    answer(true);
}

int main()
{
    unsigned n;
    std::cin >> n;

    unsigned ax, ay;
    std::cin >> ax >> ay;

    unsigned bx, by;
    std::cin >> bx >> by;

    unsigned cx, cy;
    std::cin >> cx >> cy;

    solve(n, ax, ay, bx, by, cx, cy);

    return 0;
}

