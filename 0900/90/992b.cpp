#include <iostream>
#include <numeric>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned l, unsigned r, unsigned x, unsigned y)
{
    const auto check = [=](unsigned b) {
        if (b < l || b > r)
            return false;

        const auto a = 1ull * x * y / b;
        if (a < l || a > r)
            return false;

        return std::gcd(a, b) == x;
    };

    unsigned k = 0;
    for (unsigned i = 1; i * i <= y; ++i) {
        if (y % i != 0)
            continue;

        k += check(i);
        if (i * i != y)
            k += check(y / i);
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned l, r, x, y;
    std::cin >> l >> r >> x >> y;

    solve(l, r, x, y);

    return 0;
}
