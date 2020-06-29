#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n, size_t m, size_t k)
{
    const size_t c = n / k;
    if (m <= c)
        return answer(m);

    m -= c;

    const size_t d = (m + k - 2) / (k - 1);
    answer(c - d);
}

void test_case()
{
    size_t n, m, k;
    std::cin >> n >> m >> k;

    solve(n, m, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

