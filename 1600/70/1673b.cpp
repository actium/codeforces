#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    size_t p = 0;
    for (bool v[26] = {}; p < n && !v[s[p]-'a']; ++p)
        v[s[p]-'a'] = true;

    for (size_t i = p; i < n; ++i) {
        if (s[i] != s[i-p])
            return answer(false);
    }

    answer(true);
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
