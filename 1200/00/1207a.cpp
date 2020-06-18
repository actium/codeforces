#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t b, size_t p, size_t f, size_t h, size_t c)
{
    if (b / 2 < p + f) {
        if (h > c) {
            p = std::min(b / 2, p);
            f = b / 2 - p;
        } else {
            f = std::min(b / 2, f);
            p = b / 2 - f;
        }
    }

    answer(p * h + f * c);
}

void test_case()
{
    size_t b, p, f, h, c;
    std::cin >> b >> p >> f >> h >> c;

    solve(b, p, f, h, c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

