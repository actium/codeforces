#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned f[2] = {};
    for (const char c : s)
        ++f[c & 1];

    for (size_t i = 0; i < n; ++i) {
        const unsigned x = s[i] - '0';
        if (f[x ^ 1]-- == 0)
            return answer(n - i);
    }

    answer(0);
}

void test_case()
{
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
