#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    size_t x = 0;
    for (size_t i = 1; i < n; ++i) {
        if (s[i] <= s[x])
            x = i;
    }

    answer(s[x] + s.substr(0, x) + s.substr(x + 1));
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
