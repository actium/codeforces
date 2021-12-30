#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    size_t k = 1;
    for (size_t i = 1; i < n && s[i] < s[0] && s[i] <= s[i-1]; ++i)
        ++k;

    std::string p(2 * k, ' ');
    for (size_t i = 0; i < k; ++i)
        p[i] = p[2*k-1-i] = s[i];

    answer(p);
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
