#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned x, unsigned y)
{
    unsigned k = 0;
    for (unsigned a = y, b = y, c = y; c < x; ++k) {
        const unsigned d = a + b - 1;
        c = b;
        b = a;
        a = d;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned x, y;
    std::cin >> x >> y;

    solve(x, y);

    return 0;
}
