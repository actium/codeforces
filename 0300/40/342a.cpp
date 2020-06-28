#include <algorithm>
#include <iostream>

void answer(int v)
{
    std::cout << v << '\n';
}

void answer(unsigned x, unsigned y, unsigned z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void solve(size_t f[8])
{
    if (f[5] != 0 || f[7] != 0)
        return answer(-1);

    size_t f124 = std::min({ f[1], f[2], f[4] });
    f[1] -= f124;
    f[2] -= f124;
    f[4] -= f124;

    size_t f126 = std::min({ f[1], f[2], f[6] });
    f[1] -= f126;
    f[2] -= f126;
    f[6] -= f126;

    size_t f136 = std::min({ f[1], f[3], f[6] });
    f[1] -= f136;
    f[3] -= f136;
    f[6] -= f136;

    if (f[1] != 0 || f[2] != 0 || f[3] != 0 || f[4] != 0 || f[6] != 0)
        return answer(-1);

    while (f124-- > 0)
        answer(1, 2, 4);
    while (f126-- > 0)
        answer(1, 2, 6);
    while (f136-- > 0)
        answer(1, 3, 6);
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t f[8] = { 0 };
    for (size_t i = 0; i < n; ++i) {
        unsigned a;
        std::cin >> a;

        ++f[a];
    }

    solve(f);

    return 0;
}

