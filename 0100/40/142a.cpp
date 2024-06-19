#include <iostream>

using integer = unsigned long long;

void answer(integer x, integer y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n)
{
    integer lb = ~integer(0), ub = 0;

    const auto check = [&](unsigned a, unsigned b, unsigned c) {
        const integer v = integer(a + 1) * (b + 2) * (c + 2);
        lb = std::min(lb, v);
        ub = std::max(ub, v);
    };

    for (unsigned a = 1; a * a * a <= n; ++a) {
        if (n % a != 0)
            continue;

        for (unsigned b = a; a * b * b <= n; ++b) {
            if ((n / a) % b != 0)
                continue;

            check(a, b, n / a / b);
            check(n / a / b, a, b);
        }
    }

    answer(lb - n, ub - n);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
