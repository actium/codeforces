#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned r)
{
    using integer = unsigned long long;

    const integer bi = 1ull * r * r, be = (r + 1ull) * (r + 1);

    unsigned k = 0;
    for (integer x = 0, y = r, h = r; x <= r; ++x) {
        while (x * x + h * h >= be)
            --h;

        while (y > 0 && x * x + y * y >= bi)
            --y;

        k += h - y;
    }

    answer(4 * k);
}

void test_case()
{
    unsigned r;
    std::cin >> r;

    solve(r);
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
