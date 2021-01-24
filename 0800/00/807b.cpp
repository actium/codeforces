#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned p, unsigned x, unsigned y)
{
    const auto check = [=](int d) {
        unsigned i = (x + d) / 50 % 475;
        for (unsigned k = 25; k > 0; --k) {
            i = (i * 96 + 42) % 475;
            if (26 + i == p)
                return true;
        }
        return false;
    };

    int d = int(y - x) / 50 * 50;
    while (!check(d))
        d += 50;

    answer((std::max(0, d) + 50) / 100);
}

int main()
{
    unsigned p, x, y;
    std::cin >> p >> x >> y;

    solve(p, x, y);

    return 0;
}

