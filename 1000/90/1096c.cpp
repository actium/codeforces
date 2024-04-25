#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a)
{
    const auto check = [a](unsigned n) {
        for (unsigned i = 1; i <= n - 2; ++i) {
            if (i * 180 == n * a)
                return true;
        }
        return false;
    };

    unsigned n = 3;
    while (!check(n))
        ++n;

    answer(n);
}

void test_case()
{
    unsigned a;
    std::cin >> a;

    solve(a);
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
