#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n, unsigned x, unsigned y)
{
    answer(x + y < n ? 1 : std::min(x + y - n + 1, n), std::min(x + y - 1, n));
}

void test_case()
{
    unsigned n, x, y;
    std::cin >> n >> x >> y;

    solve(n, x, y);
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
