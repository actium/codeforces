#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s1, const std::string& s2)
{
    const size_t n = s1.length();

    for (size_t i = 0; i < n; ++i) {
        if (s1[i] == '1' && s2[i] == '1')
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s1, s2;
    std::cin >> s1 >> s2;

    solve(s1, s2);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
