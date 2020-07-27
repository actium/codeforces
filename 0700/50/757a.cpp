#include <algorithm>
#include <iostream>
#include <string>

size_t index(char c)
{
    return isupper(c) ? c - 'A' : 26 + c - 'a';
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    unsigned f[2 * 26] = {};
    for (const char c : s)
        ++f[index(c)];

    answer(std::min({ f[index('B')], f[index('u')]/2, f[index('l')], f[index('b')], f[index('a')]/2, f[index('s')], f[index('r')] }));
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

