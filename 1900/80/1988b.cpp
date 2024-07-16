#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    std::string t;
    for (const char c : s) {
        if (c == '1' || t.empty() || t.back() == '1')
            t.push_back(c);
    }

    unsigned v = 0;
    for (const char c : t)
        v += c - '0';

    answer(2 * v > t.length());
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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
