#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const auto check = [&s](size_t i) {
        const char c = std::tolower(s[i]);
        for (size_t j = 0; j < i; ++j) {
            if (s[j] == c)
                return true;
        }
        return false;
    };

    for (size_t i = 0; i < 6; ++i) {
        if (isupper(s[i]) && !check(i))
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    std::string s;
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
