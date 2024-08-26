#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned m, unsigned k)
{
    answer(std::min(n, k) * std::min(m, k));
}

void test_case()
{
    unsigned n, m, k;
    std::cin >> n >> m >> k;

    solve(n, m, k);
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
