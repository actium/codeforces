#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned a, unsigned b, unsigned c)
{
    const unsigned t = a + b + c;
    if (t % 2 != 0)
        return no_answer();

    answer(std::min(t / 2, a + b));
}

void test_case()
{
    unsigned a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);
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
