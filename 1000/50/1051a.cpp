#include <iostream>
#include <string>
#include <vector>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

bool check(std::string& s, size_t x, char r)
{
    std::swap(s[x], r);

    unsigned q = 0;
    for (const char c : s) {
        q |= !!isdigit(c) << 0;
        q |= !!islower(c) << 1;
        q |= !!isupper(c) << 2;
    }
    if (q == 7)
        return true;

    std::swap(s[x], r);
    return false;
};

void solve(std::string& s)
{
    const size_t n = s.length();

    bool v = check(s, 0, s[0]);
    for (size_t i = 0; i < n && !v; ++i)
        v = check(s, i, '1') || check(s, i, 'a') || check(s, i, 'A');

    if (!v && isdigit(s[0])) {
        s[0] = 'a';
        v = check(s, 1, 'A');
    }
    if (!v && islower(s[0])) {
        s[0] = '1';
        v = check(s, 1, 'A');
    }
    if (!v && isupper(s[0])) {
        s[0] = '1';
        v = check(s, 1, 'a');
    }

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

