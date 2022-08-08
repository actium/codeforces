#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    const size_t n = a.length(), m = b.length(), k = m - 1;

    answer(a.find(b[0]) < n - k && a.compare(n - k, k, b, 1, k) == 0);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::string a, b;
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
