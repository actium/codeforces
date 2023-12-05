#include <iostream>

using integer = unsigned long long;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, integer p, integer l, integer t)
{
    const auto check = [=](unsigned x) {
        const unsigned q = std::min((n + 6) / 7, (n - x) * 2);
        return (n - x) * l + q * t >= p;
    };

    unsigned lb = 0, ub = n;
    while (lb + 1 < ub) {
        const unsigned mid = (lb + ub) / 2;
        (check(mid) ? lb : ub) = mid;
    }

    answer(lb);
}

void test_case()
{
    integer n, p, l, t;
    std::cin >> n >> p >> l >> t;

    solve(n, p, l, t);
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
