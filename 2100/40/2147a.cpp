#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned x, unsigned y)
{
    if (y > x)
        return answer(2);

    if (y + 1 < x && y != 1)
        return answer(3);

    no_answer();
}

void test_case()
{
    unsigned x, y;
    std::cin >> x >> y;

    solve(x, y);
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
