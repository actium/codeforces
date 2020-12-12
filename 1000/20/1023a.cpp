#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::string& s, std::string& t)
{
    size_t x = s.find('*');
    if (x == std::string::npos)
        return answer(s == t);

    if (s.length() - 1 > t.length())
        return answer(false);

    if (s.substr(0, x) != t.substr(0, x))
        return answer(false);

    const size_t y = t.length() - (s.length() - ++x);
    answer(t.substr(y) == s.substr(x));
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}

