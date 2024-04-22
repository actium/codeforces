#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer n, integer m)
{
    if (m >= n)
        return answer(n);

    const auto check = [=](integer k) {
        return k * (k + 1) >= 2 * (n - m);
    };

    integer lb = 0, ub = ~0u;
    while (lb + 1 < ub) {
        const integer mid = (lb + ub) / 2;
        (check(mid) ? ub : lb) = mid;
    }

    answer(m + ub);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}
