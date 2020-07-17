#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned k = n;
    if (s.find('1', 1) != std::string::npos)
        ++k;

    answer(k / 2);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

