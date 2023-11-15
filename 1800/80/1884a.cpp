#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned sum_digits(unsigned x)
{
    unsigned s = 0;
    while (x != 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

void solve(unsigned x, unsigned k)
{
    while (sum_digits(x) % k != 0)
        ++x;

    answer(x);
}

void test_case()
{
    unsigned x, k;
    std::cin >> x >> k;

    solve(x, k);
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
