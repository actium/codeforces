#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    unsigned x = 1;
    for (unsigned i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            for (x *= i; n % i == 0; n /= i);
    }

    answer(x * n);
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
