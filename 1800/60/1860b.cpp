#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned m, unsigned k, unsigned a, unsigned b)
{
    m -= std::min(m / k, b) * k;
    m -= std::min(m / 1, a) * 1;

    const unsigned q = m / k, d = m - q * k;
    if (a < k - d)
        return answer(q + d);

    answer(std::min(q + d, q + 1));
}

void test_case()
{
    unsigned m, k, a, b;
    std::cin >> m >> k >> a >> b;

    solve(m, k, a, b);
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
