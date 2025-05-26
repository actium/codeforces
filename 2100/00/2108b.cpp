#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, unsigned x)
{
    if (n == 1 && x == 0)
        return no_answer();

    if (x == 1 - n % 2)
        return answer(n + 3);

    n -= std::min<unsigned>(n, __builtin_popcount(x));

    answer(x + n + n % 2);
}

void test_case()
{
    unsigned n, x;
    std::cin >> n >> x;

    solve(n, x);
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
