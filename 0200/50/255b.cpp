#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    unsigned f[2] = {};
    for (const char c : s)
        ++f[c - 'x'];

    if (f[0] > f[1])
        answer(std::string(f[0] - f[1], 'x'));
    else
        answer(std::string(f[1] - f[0], 'y'));
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

