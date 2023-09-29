#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    const size_t n = a.length();

    for (size_t i = 1; i < n; ++i) {
        if (a[i-1] == '0' && a[i] == '1' && b[i-1] == '0' && b[i] == '1')
            return answer(true);
    }

    answer(false);
}

void test_case()
{
    std::string a, b;
    std::cin >> a >> b;

    solve(a, b);
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
