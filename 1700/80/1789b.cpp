#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    size_t x = n;
    for (size_t i = 0; i < n / 2; ++i) {
        if (s[i] == s[n-1-i])
            continue;

        if (x != n && i != x + 1)
            return answer(false);

        x = i;
    }

    answer(true);
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
