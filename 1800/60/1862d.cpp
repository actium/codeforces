#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer n)
{
    const auto f = [n](integer x) {
        return x * (x - 1) / 2;
    };

    integer lb = 0, ub = 2000000001;
    while (lb + 1 < ub) {
        const integer mid = (lb + ub) / 2;
        (f(mid) <= n ? lb : ub) = mid;
    }

    answer(lb + n - f(lb));
}

void test_case()
{
    integer n;
    std::cin >> n;

    solve(n);
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
