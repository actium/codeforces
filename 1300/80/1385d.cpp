#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

unsigned count(const std::string& s, char c)
{
    const size_t n = s.length();
    if (n == 1)
        return s[0] != c;

    const size_t m = n / 2;

    unsigned f[2] = {};
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == c)
            ++f[i < m];
    }

    return std::min(m - f[0] + count(s.substr(0, m), c+1), m - f[1] + count(s.substr(m), c+1));
}

void solve(const std::string& s)
{
    answer(count(s, 'a'));
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

