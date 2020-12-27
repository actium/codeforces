#include <iostream>

void answer(unsigned v)
{
    constexpr const char* s[2] = { "Ciel", "Hanako" };
    std::cout << s[v] << '\n';
}

void solve(unsigned x, unsigned y)
{
    unsigned t = 1;
    while (x * 100 + y * 10 >= 220 && y >= 2) {
        if (t == 1) {
            const unsigned c = std::min(x, 2u);
            x -= c, y -= 22 - c * 10;
        } else {
            const unsigned c = std::min((y - 2) / 10, 2u) * 10 + 2;
            y -= c, x -= (22 - c) / 10;
        }
        t ^= 1;
    }

    answer(t);
}

int main()
{
    unsigned x, y;
    std::cin >> x >> y;

    solve(x, y);

    return 0;
}

