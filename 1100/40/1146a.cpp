#include <algorithm>
#include <iostream>
#include <string>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(std::string& s)
{
    std::sort(s.begin(), s.end());

    size_t n = s.length();
    while (s[n/2] != 'a')
        --n;

    answer(n);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

