#include <iostream>
#include <string>

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned k = 0;
    for (size_t i = 0; i < n / 2; ++i)
        k += (s[i] != s[n-1-i]);

    for (unsigned i = 0; i < k; ++i)
        std::cout << '0';

    if (n % 2 == 0) {
        for (unsigned i = 0; i <= n - 2 * k; ++i)
            std::cout << char('1' - i % 2);
    } else {
        for (unsigned i = 0; i <= n - 2 * k; ++i)
            std::cout << '1';
    }

    for (unsigned i = 0; i < k; ++i)
        std::cout << '0';

    std::cout << '\n';
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
