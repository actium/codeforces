#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    unsigned v[26] = {};
    for (const char c : s)
        v[c - 'a'] = 1;

    unsigned k = 0;
    for (size_t i = 0; i < 26; ++i)
        k += v[i];

    answer(k - 1);
}

void test_case()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s + t);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
