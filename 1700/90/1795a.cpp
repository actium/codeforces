#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::string& s, std::string& t)
{
    s.append(t.rbegin(), t.rend());

    unsigned k = 0;
    for (size_t i = 1; i < s.length(); ++i)
        k += (s[i] == s[i-1]);

    answer(k < 2);
}

void test_case()
{
    size_t n, m;
    std::cin >> n >> m;

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
