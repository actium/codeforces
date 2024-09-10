#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned k)
{
    using integer = long long;

    const auto count = [k](unsigned n) {
        return (2 * k + n - 1ll) * n / 2;
    };

    const auto evaluate = [&](unsigned x) {
        return 2 * count(x) - count(n);
    };

    unsigned lb = 0, ub = n;
    while (lb + 1 < ub) {
        const unsigned mid = (lb + ub) / 2;
        (evaluate(mid) < 0 ? lb : ub) = mid;
    }

    answer(std::min(std::abs(evaluate(lb)), std::abs(evaluate(ub))));
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);
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
