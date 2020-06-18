#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    size_t f[26] = {};
    for (const char c : s)
        ++f[c - 'a'];

    std::string number;
    for (size_t i = 0; i < f['n' - 'a']; ++i)
        number += "1 ";
    for (size_t i = 0; i < f['z' - 'a']; ++i)
        number += "0 ";
    number.pop_back();

    answer(number);
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

