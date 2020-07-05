#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    answer((s.length() + 1) * 25 + 1);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

