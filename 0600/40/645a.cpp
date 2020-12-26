#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(std::string a, std::string b)
{
    a.erase(a.find('X'), 1);
    b.erase(b.find('X'), 1);

    answer((a + a).find(b) != std::string::npos);
}

int main()
{
    char a[4];
    std::cin >> a[0] >> a[1] >> a[3] >> a[2];

    char b[4];
    std::cin >> b[0] >> b[1] >> b[3] >> b[2];

    solve(std::string(a, 4), std::string(b, 4));

    return 0;
}

