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

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i)
        k += (a[i] == c[i] || b[i] == c[i]);

    answer(k != n);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string a, b, c;
    std::cin >> a >> b >> c;

    solve(a, b, c);
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
