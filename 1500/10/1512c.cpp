#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(std::string& s, unsigned a, unsigned b)
{
    const size_t n = a + b, m = n / 2;

    const auto index = [](char c) {
        return c - '0';
    };

    unsigned f[2] = {};
    for (size_t i = 0; i < m; ++i) {
        if (s[i] == '?' && s[n-1-i] != '?')
            s[i] = s[n-1-i];

        if (s[n-1-i] == '?' && s[i] != '?')
            s[n-1-i] = s[i];

        if (s[i] != '?')
            f[index(s[i])] += 2;

        if (s[i] != s[n-1-i])
            return no_answer();
    }

    for (size_t i = 0; i < m; ++i) {
        if (s[i] == '?' && f[index('0')] + 2 <= a) {
            s[i] = s[n-1-i] = '0';
            f[index('0')] += 2;
        }
        if (s[i] == '?' && f[index('1')] + 2 <= b) {
            s[i] = s[n-1-i] = '1';
            f[index('1')] += 2;
        }
    }

    if (n % 2 == 1) {
        if (s[m] == '?' && f[index('0')] < a)
            s[m] = '0';

        if (s[m] == '?' && f[index('1')] < b)
            s[m] = '1';

        if (s[m] != '?')
            ++f[index(s[m])];
    }

    if (f[0] == a && f[1] == b)
        return answer(s);

    no_answer();
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    std::string s;
    std::cin >> s;

    solve(s, a, b);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

