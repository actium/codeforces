#include <algorithm>
#include <iostream>
#include <string>

void answer(const char* v)
{
    std::cout << v << '\n';
}

void solve(std::string name)
{
    std::sort(name.begin(), name.end());
    name.erase(std::unique(name.begin(), name.end()), name.end());

    constexpr const char* s[2] = { "CHAT WITH HER!", "IGNORE HIM!" };
    answer(s[name.length() % 2]);
}

int main()
{
    std::string name;
    std::cin >> name;

    solve(name);

    return 0;
}

