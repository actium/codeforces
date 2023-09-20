#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length();

    unsigned b[26] = {};
    for (size_t i = 0; i < n; ++i) {
        ++b[s[i] - 'a'];
        --b[t[i] - 'a'];
    }

    for (size_t i = 0; i < 26; ++i) {
        if (b[i] != 0)
            return answer(false);
    }

    if (n < 4)
        return answer(s == t);

    for (size_t i = n - 3; i < 3; ++i) {
        if (s[i] != t[i])
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

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
