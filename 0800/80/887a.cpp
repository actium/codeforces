#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "no", "yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned k = 0;
    for (size_t i = s.find('1'); i < n; ++i)
        k += (s[i] == '0');

    answer(k >= 6);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

