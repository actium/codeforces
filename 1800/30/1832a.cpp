#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    for (size_t i = 1; i < n / 2; ++i) {
        if (s[i] != s[i-1])
            return answer(true);
    }

    answer(false);
}

void test_case()
{
    std::string s;
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
