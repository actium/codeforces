#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned x, unsigned y, unsigned z)
{
    const unsigned a = z | x, b = x | y, c = y | z;

    answer((a & b) == x && (b & c) == y && (c & a) == z);
}

void test_case()
{
    unsigned x, y, z;
    std::cin >> x >> y >> z;

    solve(x, y, z);
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
