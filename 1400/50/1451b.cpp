#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, size_t l, size_t r)
{
    const size_t n = s.length();

    for (size_t i = 0; i < l; ++i) {
        if (s[i] == s[l])
            return answer(true);
    }
    for (size_t i = r+1; i < n; ++i) {
        if (s[i] == s[r])
            return answer(true);
    }

    answer(false);
}

void test_case()
{
    size_t n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;

    while (q-- > 0) {
        size_t l, r;
        std::cin >> l >> r;

        solve(s, l-1, r-1);
    }
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

