#include <iostream>

void answer(int x, int y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(int x, int y, int r)
{
    answer(x + r, y);
}

void test_case()
{
    int x, y, r;
    std::cin >> x >> y >> r;

    solve(x, y, r);
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
