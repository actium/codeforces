#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    unsigned f[26] = {};
    for (const char c : s)
        ++f[c-'a'];

    std::string t;
    while (t.length() < s.length()) {
        for (size_t i = 0; i < 26; ++i) {
            if (f[i] != 0) {
                t.push_back('a' + i);
                --f[i];
            }
        }
    }

    answer(t);
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
