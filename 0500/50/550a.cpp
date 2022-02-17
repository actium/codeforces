#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const size_t ab = s.find("AB");
    if (ab != std::string::npos && s.find("BA", ab + 2) != std::string::npos)
        return answer(true);

    const size_t ba = s.find("BA");
    if (ba != std::string::npos && s.find("AB", ba + 2) != std::string::npos)
        return answer(true);

    answer(false);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
