#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, char c)
{
    const size_t n = s.length();

    for (size_t i = 0; i < n; ++i) {
        if (s[i] == c && i % 2 == 0 && (n-1-i) % 2 == 0)
            return answer(true);
    }

    answer(false);
}

void test_case()
{
    std::string s;
    std::cin >> s;

    char c;
    std::cin >> c;

    solve(s, c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
