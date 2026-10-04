#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned x, unsigned y)
{
    const unsigned s = x + y;

    unsigned k = 0;
    for (unsigned b = 1 << 30; (x ^ y) != s; b >>= 1) {
        if ((s & b) != 0)
            continue;

        while ((x & b) != 0 || (y & b) != 0) {
            if ((x & b) != 0) {
                const unsigned d = x & (b - 1);
                x -= d + 1;
                y += d + 1;
                k += d + 1;
            }
            if ((y & b) != 0) {
                const unsigned d = y & (b - 1);
                x -= b - d;
                y += b - d;
                k += b - d;
            }
        }
    }

    answer(s, k);
}

void test_case()
{
    unsigned x, y;
    std::cin >> x >> y;

    solve(x, y);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
