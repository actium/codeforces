#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length(), m = t.length();

    const auto test = [&](size_t i, size_t d) {
        size_t j = 0;
        if (s[i] != t[j++])
            return false;

        while (d-- > 0) {
            if (++i == n || s[i] != t[j++])
                return false;
        }
        while (i-- != 0 && j < m) {
            if (s[i] != t[j++])
                return false;
        }
        return j == m;
    };

    for (size_t i = 0; i < n; ++i) {
        for (size_t d = 0; d <= m; ++d) {
            if (test(i, d))
                return answer(true);
        }
    }

    answer(false);
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
