#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    unsigned k = 0;
    for (unsigned x = 2; x * x <= n; ++x) {
        if (n % x != 0)
            continue;

        for (++k; n % x == 0; n /= x)
            ++k;
    }

    answer(k + (n == 1 ? -1 : 1));
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
