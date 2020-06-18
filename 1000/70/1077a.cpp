#include <iostream>

void answer(long long v)
{
    std::cout << v << '\n';
}

void solve(long long a, long long b, size_t k)
{
    answer((k / 2) * (a - b) + (k % 2) * a);
}

void test_case()
{
    size_t a, b, k;
    std::cin >> a >> b >> k;

    solve(a, b, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

