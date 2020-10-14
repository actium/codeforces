#include <iostream>

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void solve(unsigned r1, unsigned c1, unsigned r2, unsigned c2)
{
    const unsigned dr = abs(r1 - r2);
    const unsigned dc = abs(c1 - c2);

    answer((dr != 0) + (dc != 0), dr % 2 == dc % 2 ? 1 + (dr != dc) : 0, std::max(dr, dc));
}

int main()
{
    unsigned r1, c1, r2, c2;
    std::cin >> r1 >> c1 >> r2 >> c2;

    solve(r1, c1, r2, c2);

    return 0;
}

