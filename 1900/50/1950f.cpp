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
    if (c != a + 1)
        return no_answer();

    if (a == 0)
        return answer(b);

    const unsigned h = __builtin_clz(1) - __builtin_clz(a) + 1;
    b -= std::min(b, (1 << h) - (a + 1));

    answer(h + (b + c - 1) / c);
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
