#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    s.push_back('R');

    size_t x = 0;
    while (s[x] == '?')
        ++x;

    for (size_t i = x; i-- > 0; ) {
        if (s[i] == '?')
            s[i] = s[i+1] ^ 'B' ^ 'R';
    }
    for (size_t i = x; ++i < n; ) {
        if (s[i] == '?')
            s[i] = s[i-1] ^ 'B' ^ 'R';
    }

    s.pop_back();

    answer(s);
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
