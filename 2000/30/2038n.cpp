#include <iostream>
#include <string>

void answer(const std::string& s)
{
    std::cout << s << '\n';
}

void solve(std::string& s)
{
    if (s[0] == s[2])
        s[1] = '=';
    else
        s[1] = (s[0] < s[2] ? '<' : '>');

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
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
