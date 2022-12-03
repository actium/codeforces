#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n)
{
    unsigned x = 1;
    for (unsigned i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            x = n / i;
            break;
        }
    }

    answer(x, n - x);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
