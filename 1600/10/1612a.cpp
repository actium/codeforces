#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void no_answer()
{
    std::cout << -1 << ' ' << -1 << '\n';
}

void solve(unsigned x, unsigned y)
{
    if ((x + y) % 2 == 0)
        return answer(x / 2, (y + 1) / 2);

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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
