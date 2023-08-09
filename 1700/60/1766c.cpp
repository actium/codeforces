#include <array>
#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

bool check(const std::array<std::string, 2>& c, size_t i, size_t j, bool v)
{
    if (!v && c[i^1][j] == 'B')
        return check(c, i^1, j, true);

    if (j + 1 == c[0].length())
        return true;

    return c[i][j+1] == 'B' && check(c, i, j+1, false);
}

void solve(const std::array<std::string, 2>& c)
{
    answer(c[0][0] == 'B' && check(c, 0, 0, false) || c[1][0] == 'B' && check(c, 1, 0, false));
}

void test_case()
{
    size_t m;
    std::cin >> m;

    std::array<std::string, 2> c;
    std::cin >> c[0] >> c[1];

    solve(c);
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
