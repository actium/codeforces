#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned solve(unsigned s, unsigned d)
{
    if (s <= d)
        return s;

    return solve(s - d, d - 1) * 10 + d;
}

void solve(unsigned s)
{
    answer(solve(s, 9));
}

void test_case()
{
    unsigned s;
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
