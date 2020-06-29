#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n)
{
    size_t k = 0;
    for (size_t m = ~0u >> k; n % m != 0; ++k, m = ~0u >> k);

    answer(n / (~0u >> k));
}

void test_case()
{
    size_t n;
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


