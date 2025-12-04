#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned y, unsigned r)
{
    answer(std::min(y / 2 + r, n));
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    unsigned y, r;
    std::cin >> y >> r;

    solve(n, y, r);
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
