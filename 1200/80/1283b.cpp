#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n, size_t k)
{
    const size_t a = n / k;
    const size_t d = std::min(n - a * k, k / 2);

    answer(a * k + d);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    solve(n, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

