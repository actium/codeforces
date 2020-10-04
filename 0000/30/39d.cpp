#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned x1, unsigned y1, unsigned z1, unsigned x2, unsigned y2, unsigned z2)
{
    answer(x1 == x2 || y1 == y2 || z1 == z2);
}

int main()
{
    unsigned x1, y1, z1;
    std::cin >> x1 >> y1 >> z1;

    unsigned x2, y2, z2;
    std::cin >> x2 >> y2 >> z2;

    solve(x1, y1, z1, x2, y2, z2);

    return 0;
}

