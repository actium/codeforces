#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    size_t l = 0;
    while (l < n && s[l] != '[')
        ++l;

    while (l < n && s[l] != ':')
        ++l;

    size_t r = n-1;
    while (r > l && s[r] != ']')
        --r;

    while (r > l && s[r] != ':')
        --r;

    if (l >= r)
        return no_answer();

    unsigned k = 4;
    for (size_t i = l + 1; i < r; ++i)
        k += (s[i] == '|');

    answer(k);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

