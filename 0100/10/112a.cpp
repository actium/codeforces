#include <iostream>
#include <string>

#include <cstring>

void answer(int v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s1, const std::string& s2)
{
    answer(strcasecmp(s1.c_str(), s2.c_str()));
}

int main()
{
    std::string s1, s2;
    std::cin >> s1 >> s2;

    solve(s1, s2);

    return 0;
}

