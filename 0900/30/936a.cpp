#include <iomanip>
#include <iostream>

using integer = unsigned long long;

void answer(double x)
{
    std::cout << std::fixed << std::setprecision(10) << x << '\n';
}

void solve(integer k, integer d, integer t)
{
    if (k % d == 0)
        return answer(t);

    t *= 2;

    const integer p = k + d - k % d, q = t / (k + p), r = t - q * (k + p);

    answer(p * q + (r <= 2 * k ? r / 2.0 : r - k));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer k, d, t;
    std::cin >> k >> d >> t;

    solve(k, d, t);

    return 0;
}
