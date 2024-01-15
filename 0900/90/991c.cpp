#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer n)
{
    const auto check = [n](integer k) {
        integer s = 0;
        for (integer r = n; r != 0; ) {
            const integer d = std::min(r, k);
            s += d;
            r -= d;
            r -= r / 10;
        }
        return 2 * s >= n;
    };

    integer lb = 0, ub = n;
    while (lb + 1 < ub) {
        const integer mid = (lb + ub) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    answer(ub);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer n;
    std::cin >> n;

    solve(n);

    return 0;
}
