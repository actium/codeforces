#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned a, unsigned b)
{
    if (a >= b)
        return answer(1ull * n * a);

    const unsigned k = b - a + 1;
    if (k <= n)
        return answer(integer(a + b) * k / 2 + integer(n - k) * a);

    answer(integer(2 * b - n + 1) * n / 2);
}

void test_case()
{
    unsigned n, a, b;
    std::cin >> n >> a >> b;

    solve(n, a, b);
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
