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

    size_t p[256*256] = {};
    for (size_t i = 1; i < n; ++i) {
        const size_t x = s[i-1] * 26 + s[i];
        if (p[x] == 0)
            p[x] = i;

        if (i - p[x] > 1)
            return answer(true);
    }

    answer(false);
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
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
