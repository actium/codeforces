#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned k, unsigned n, unsigned a, unsigned b)
{
    if (1ull * n * b >= k)
        return no_answer();

    const auto f = [=](unsigned x) {
        const unsigned r = n - x;
        return 1ull * r * b + 1ull * x * a < k;
    };

    unsigned lb = 0, ub = k;
    while (lb + 1 < ub) {
        const unsigned mid = lb + (ub - lb) / 2;
        (f(mid) ? lb : ub) = mid;
    }

    answer(lb);
}

void test_case()
{
    unsigned k, n, a, b;
    std::cin >> k >> n >> a >> b;

    solve(k, n, a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
