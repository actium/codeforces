#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, const std::string& t, const std::string& p)
{
    const size_t n = t.length(), m = s.length();

    unsigned f[26] = {};
    for (const char c : p)
        ++f[c - 'a'];

    size_t j = 0;
    for (size_t i = 0; i < n; ++i) {
        if (j < m && s[j] == t[i]) {
            ++j;
            continue;
        }

        if (f[t[i] - 'a']-- == 0)
            return answer(false);
    }

    answer(j == m);
}

void test_case()
{
    std::string s, t, p;
    std::cin >> s >> t >> p;

    solve(s, t, p);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

