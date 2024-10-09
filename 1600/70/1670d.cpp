#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    unsigned lb = 1, ub = 38730;
    while (ub - lb > 1) {
        const unsigned mid = (lb + ub) / 2;
        (mid * mid * 2 / 3 < n ? lb : ub) = mid;
    }

    answer(ub);
}

void test_case()
{
    unsigned n;
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
