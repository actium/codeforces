#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, unsigned k, unsigned x)
{
    if (n < k || x + 1 < k)
        return no_answer();

    if (x == k)
        --x;

    answer((k - 1) * k / 2 + (n - k) * x);
}

void test_case()
{
    unsigned n, k, x;
    std::cin >> n >> k >> x;

    solve(n, k, x);
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
