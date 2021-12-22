#include <iostream>
#include <string>
#include <vector>

void no_answer()
{
    std::cout << "NO" << '\n';
}

void answer(const std::vector<std::string>& v)
{
    std::cout << "YES" << '\n';

    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned f[2] = {};
    for (const char c : s)
        ++f[c - '1'];

    if (f[1] == 1 || f[1] == 2)
        return no_answer();

    const auto next = [&](size_t i) {
        size_t j = 1;
        while (s[(i + j) % n] != '2')
            ++j;

        return (i + j) % n;
    };

    std::vector<std::string> t(n, std::string(n, '='));
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '2') {
            const size_t j = next(i);
            t[i][j] = '+';
            t[j][i] = '-';
        }

        t[i][i] = 'X';
    }

    answer(t);
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
