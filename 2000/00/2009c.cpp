#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned x, unsigned y, unsigned k)
{
    const unsigned sx = (x + k - 1) / k, sy = (y + k - 1) / k;

    answer(sy < sx ? 2 * sx - 1 : 2 * sy);
}

void test_case()
{
    unsigned x, y, k;
    std::cin >> x >> y >> k;

    solve(x, y, k);
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
