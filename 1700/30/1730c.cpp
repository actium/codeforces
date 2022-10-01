#include <algorithm>
#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& s, size_t p)
{
    const size_t n = s.length();
    if (p == n)
        return;

    size_t x = p;
    for (size_t i = p; i < n; ++i) {
        if (s[i] <= s[x])
            x = i;
    }

    for (size_t i = p; i < x; ++i) {
        if (s[i] > s[x])
            s[i] = std::min<char>(s[i] + 1, '9');
    }

    solve(s, x+1);
}

void solve(std::string& s)
{
    solve(s, 0);
    std::sort(s.begin(), s.end());
    answer(s);
}

void test_case()
{
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
