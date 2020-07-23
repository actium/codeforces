#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    bool v[26] = {};
    for (const char c : s)
        v[c - 'a'] = true;

    for (const char c : t) {
        if (v[c - 'a'])
            return answer(true);
    }

    answer(false);
}

void test_case()
{
    std::string s;
    std::cin >> s;

    std::string t;
    std::cin >> t;

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

