#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned l, unsigned r, unsigned k)
{
    if (r == 1)
        return answer(false);

    if (r == l)
        return answer(true);

    answer((r - l) / 2 + (l % 2 == 1 || r % 2 == 1) <= k);
}

void test_case()
{
    unsigned l, r, k;
    std::cin >> l >> r >> k;

    solve(l, r, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
