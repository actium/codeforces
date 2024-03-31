#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    if (n % 2 == 1)
        return no_answer();

    unsigned f[26] = {};
    for (const char c : s) {
        if (++f[c-'a'] > n/2)
            return no_answer();
    }

    unsigned g[26] = {};
    for (size_t i = 0, j = n-1; i < j; ++i, --j) {
        if (s[i] == s[j])
            ++g[s[i]-'a'];
    }

    unsigned c = 0, q = 0;
    for (size_t i = 0; i < 26; ++i) {
        c = std::max(c, g[i]);
        q += g[i];
    }

    answer(std::max(c, (q + 1) / 2));
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
