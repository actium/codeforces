#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(int a, int b, int c, int d)
{
    if (d < b)
        return no_answer();

    const int dy = d - b;
    if (a + dy < c)
        return no_answer();

    answer(2 * dy + a - c);
}

void test_case()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    solve(a, b, c, d);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
