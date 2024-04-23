#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer n, integer s)
{
    const auto check = [=](integer x) {
        unsigned d = 0;
        for (integer v = x; v != 0; v /= 10)
            d += v % 10;

        return x - d >= s;
    };

    integer lb = 0, ub = ~integer(0);
    while (lb + 1 < ub) {
        const integer mid = (lb + ub) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    answer(n >= ub ? n - ub + 1 : 0);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer n, s;
    std::cin >> n >> s;

    solve(n, s);

    return 0;
}
