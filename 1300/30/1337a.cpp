#include <iostream>

void answer(size_t x, size_t y, size_t z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void solve(size_t a, size_t b, size_t c, size_t d)
{
    for (size_t x = a; x <= b; ++x) {
        for (size_t y = std::max(b, c - x + 1); y <= c; ++y) {
            for (size_t z = c; z < std::min(d + 1, x + y); ++z) {
                if (x + z > y && y + z > x)
                    return answer(x, y, z);
            }
        }
    }
}

void test_case()
{
    size_t a, b, c, d;
    std::cin >> a >> b >> c >> d;

    solve(a, b, c, d);

    // O(1): std::cout << [a...b] << ' ' << c << ' ' << c << '\n';
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t--)
        test_case();

    return 0;
}

