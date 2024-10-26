#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    unsigned k = 0;
    for (size_t i = 0; i < s.length() && i < t.length() && s[i] == t[i]; ++i)
        ++k;

    answer(s.length() + t.length() - k + (k != 0));
}

void test_case()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);
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
