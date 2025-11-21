#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    for (size_t i = 1; i < n; ++i) {
        if (s[i-1] != '<' && s[i] != '>')
            return no_answer();
    }

    unsigned f[2] = {};
    for (const char c : s) {
        f[0] += (c == '<' || c == '*');
        f[1] += (c == '*' || c == '>');
    }

    answer(std::max(f[0], f[1]));
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
