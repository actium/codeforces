#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n, unsigned b, unsigned p)
{
    const unsigned y = n * p;

    unsigned x = 0;
    while (n > 1) {
        const unsigned k = 1 << (31 - __builtin_clz(n));
        const unsigned m = k / 2;
        x += k * b + m;
        n -= m;
    }

    answer(x, y);
}

int main()
{
    unsigned n, b, p;
    std::cin >> n >> b >> p;

    solve(n, b, p);

    return 0;
}

