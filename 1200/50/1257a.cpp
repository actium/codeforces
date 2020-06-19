#include <algorithm>
#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n, size_t x, size_t a, size_t b)
{
    if (a > b)
        std::swap(a, b);

    const size_t k = std::min(a - 1, x);
    answer(b - a + k + std::min(n - b, x - k));
}

void test_case()
{
    size_t n, x, a, b;
    std::cin >> n >> x >> a >> b;

    solve(n, x, a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

