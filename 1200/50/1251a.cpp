#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    bool p[26] = {};
    for (size_t i = 0; i < n; ++i) {
        if (i + 1 < n && s[i] == s[i+1])
            ++i;
        else
            p[s[i] - 'a'] = true;
    }

    std::string t;
    for (size_t i = 0; i < 26; ++i) {
        if (p[i])
            t.push_back('a' + i);
    }

    answer(t);
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

