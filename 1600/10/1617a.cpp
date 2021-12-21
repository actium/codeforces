#include <iostream>
#include <string>

void solve(std::string& s, const std::string& t)
{
    const auto index = [](char c) {
        return c - 'a';
    };

    unsigned f[26] = {};
    for (const char c : s)
        ++f[index(c)];

    std::string p = "abcdefghijklmnopqrstuvwxyz";
    if (t == "abc" && f[0] != 0)
        std::swap(p[index('b')], p[index('c')]);

    for (const char c : p) {
        while (f[index(c)]-- > 0)
            std::cout << c;
    }
    std::cout << '\n';
}

void test_case()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
