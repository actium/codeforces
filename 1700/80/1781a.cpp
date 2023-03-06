#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(int w, int d, int h, int a, int b, int f, int g)
{
    const int dx = std::abs(a - f), dy = std::abs(b - g);

    const int r1 = std::min(a + f, 2 * w - a - f) + h + dy;
    const int r2 = std::min(b + g, 2 * d - b - g) + h + dx;

    answer(std::min(r1, r2));
}

void test_case()
{
    int w, d, h;
    std::cin >> w >> d >> h;

    int a, b, f, g;
    std::cin >> a >> b >> f >> g;

    solve(w, d, h, a, b, f, g);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
