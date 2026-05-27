#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned x1, unsigned x2, unsigned k)
{
    const unsigned d = (x1 < x2 ? std::min(x2 - x1, x1 + n - x2) : std::min(x1 - x2, n - x1 + x2));
    answer(n > 3 ? d + k : 1);
}

void test_case()
{
    unsigned n, x1, x2, k;
    std::cin >> n >> x1 >> x2 >> k;

    solve(n, x1, x2, k);
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
