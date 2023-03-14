#include <iostream>
#include <string>

void answer(const std::string& x, const std::string& y, const std::string& z)
{
    std::cout << x << ' ' << y << ' ' << z << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    if (s[0] == s[1])
        return answer(s.substr(0, 1), s.substr(1, 1), s.substr(2));

    if (s[n-2] == s[n-1])
        return answer(s.substr(0, n - 2), s.substr(n - 2, 1), s.substr(n - 1));

    if (s[0] == s[n-1])
        return answer(s.substr(0, 1), s.substr(1, n - 2), s.substr(n - 1));

    if (s == "abab")
        return answer("ab", "a", "b");

    if (s == "baba")
        return answer("b", "a", "ba");

    answer(s.substr(0, 2), s.substr(2, n - 4), s.substr(n - 2));
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
