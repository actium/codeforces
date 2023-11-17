#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, size_t k)
{
    unsigned f[26] = {};
    for (const char c : s)
        ++f[c - 'a'];

    unsigned q = 0;
    for (size_t i = 0; i < 26; ++i)
        q += f[i] % 2;

    answer(q <= k + 1);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);
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
