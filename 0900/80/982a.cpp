#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "No", "Yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();
    if (n == 1)
        return answer(s[0] == '1');

    if (s.find("000") != std::string::npos)
        return answer(false);

    if (s.find("11") != std::string::npos)
        return answer(false);

    answer((s[0] != '0' || s[1] != '0') && (s[n-1] != '0' || s[n-2] != '0'));
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

