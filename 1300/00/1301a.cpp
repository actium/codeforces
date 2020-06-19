#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& a, const std::string& b, const std::string& c)
{
    const size_t n = a.length();

    for (size_t i = 0; i < n; ++i) {
        if (a[i] != c[i] && b[i] != c[i])
            return answer(false);
    }

    answer(true);
}

void test_case()
{
    std::string a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

