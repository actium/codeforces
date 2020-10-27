#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned l, unsigned r)
{
    answer(2 * l > r);
}

void test_case()
{
    unsigned l, r;
    std::cin >> l >> r;

    solve(l, r);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

