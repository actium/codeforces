#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    bool v[26] = {};

    char x = ' ';
    for (const char c : s) {
        if (c == x)
            continue;

        if (v[c - 'A'])
            return answer(false);

        v[c - 'A'] = true;
        x = c;
    }

    answer(true);
}

void test_case()
{
    unsigned n;
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
