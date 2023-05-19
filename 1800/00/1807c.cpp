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

    unsigned f[26][2] = {};
    for (size_t i = 0; i < n; ++i)
        ++f[s[i] - 'a'][i % 2];

    for (size_t i = 0; i < 26; ++i) {
        if (f[i][0] > 0 && f[i][1] > 0)
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

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