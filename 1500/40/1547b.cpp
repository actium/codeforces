#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    size_t x = s.find('a');
    if (x == std::string::npos)
        return answer(false);

    for (size_t d = 1; d < n; ++d) {
        if (x+d < n && s[x+d] == 'a' + d)
            continue;

        if (x > 0 && s[--x] == 'a' + d)
            continue;

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
