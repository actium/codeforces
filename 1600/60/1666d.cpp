#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    int f[26] = {};
    for (const char c : t)
        ++f[c-'A'];

    std::string r;
    for (const char c : std::string(s.rbegin(), s.rend())) {
        if (f[c-'A']-- > 0)
            r.push_back(c);
    }

    answer(std::string(r.rbegin(), r.rend()) == t);
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
