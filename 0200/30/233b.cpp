#include <iostream>

#include <cmath>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

integer search(integer n, unsigned q)
{
    integer lb = 0, ub = sqrt(n) + 1;
    while (lb + 1 < ub) {
        const integer x = lb + (ub - lb) / 2;

        const integer f = (x + q) * x;
        if (f == n)
            return x;

        (f < n ? lb : ub) = x;
    }
    return 0;
}

void solve(integer n)
{
    constexpr integer oo = ~0ull;

    constexpr auto s = [](integer x) {
        unsigned y = 0;
        while (x != 0) {
            y += x % 10;
            x /= 10;
        }
        return y;
    };

    integer b = oo;
    for (unsigned q = 1; q <= 90; ++q) {
        const integer x = search(n, q);
        if (s(x) == q)
            b = std::min(b, x);
    }

    if (b != oo)
        return answer(b);

    no_answer();
}

int main()
{
    integer n;
    std::cin >> n;

    solve(n);

    return 0;
}
