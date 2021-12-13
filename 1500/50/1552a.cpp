#include <algorithm>
#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::string t = s;
    std::sort(t.begin(), t.end());

    unsigned k = 0;
    for (size_t i = 0; i < n; ++i)
        k += (t[i] != s[i]);

    answer(k);
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
