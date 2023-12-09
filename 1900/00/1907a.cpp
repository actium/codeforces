#include <iostream>
#include <string>

void solve(const std::string& s)
{
    for (char c = '1'; c <= '8'; ++c) {
        if (c != s[1])
            std::cout << s[0] << c << '\n';
    }
    for (char c = 'a'; c <= 'h'; ++c) {
        if (c != s[0])
            std::cout << c << s[1] << '\n';
    }
}

void test_case()
{
    std::string s;
    std::cin >> s;

    solve(s);
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
