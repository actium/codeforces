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

    const auto ok = [](const std::string& s) {
        for (size_t i = 1; i < s.length(); ++i) {
            if (s[i] == s[i-1])
                return false;
        }
        return true;
    };

    if (!ok(s) && (t.front() != t.back() || !ok(t)))
        return answer(false);

    for (size_t i = 1; i < n; ++i) {
        if (s[i] == s[i-1] && s[i] == t.front())
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

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
