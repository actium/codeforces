#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "Impossible" << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    unsigned f[26] = {};
    for (const char c : t)
        ++f[c-'a'];

    for (const char c : s) {
        if (f[c-'a']-- == 0)
            return no_answer();
    }

    std::string u;
    for (size_t i = 0, j = 0; i < 26; ++i) {
        const char c = 'a' + i;

        while (j < s.length() && s[j] <= c)
            u.push_back(s[j++]);

        u.append(f[i], c);
    }

    answer(u);
}

void test_case()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);
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
