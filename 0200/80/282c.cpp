#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& a, const std::string& b)
{
    if (a.length() != b.length())
        return answer(false);

    answer((a.find('1') != std::string::npos) == (b.find('1') != std::string::npos));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
