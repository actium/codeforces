#include <iostream>

void answer(unsigned long long v)
{
    std::cout << v << '\n';
}

void solve(size_t s, size_t a, size_t b, size_t c)
{
    const size_t k = s / c;
    const size_t m = k / a;

    answer(1ull * m * b + k);
}

void test_case()
{
    size_t s, a, b, c;
    std::cin >> s >> a >> b >> c;

    solve(s, a, b, c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

