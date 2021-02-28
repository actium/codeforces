#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(int x, int y, const std::string& s)
{
    unsigned f[26] = {};
    for (const char c : s)
        ++f[c - 'A'];

    if (x < 0 && f['L'-'A'] < -x)
        return answer(false);

    if (x > 0 && f['R'-'A'] < x)
        return answer(false);

    if (y < 0 && f['D'-'A'] < -y)
        return answer(false);

    if (y > 0 && f['U'-'A'] < y)
        return answer(false);

    answer(true);
}

void test_case()
{
    int x, y;
    std::cin >> x >> y;

    std::string s;
    std::cin >> s;

    solve(x, y, s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

