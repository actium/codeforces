#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& b, const std::string& s)
{
    const size_t n = s.length();

    int p[26] = {};
    for (size_t i = 0; i < 26; ++i)
        p[b[i] - 'a'] = i;

    unsigned d = 0;
    for (size_t i = 1; i < n; ++i)
        d += abs(p[s[i] - 'a'] - p[s[i-1] - 'a']);

    answer(d);
}

void test_case()
{
    std::string b;
    std::cin >> b;

    std::string s;
    std::cin >> s;

    solve(b, s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
