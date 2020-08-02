#include <iostream>
#include <string>

unsigned rank(const std::string& c)
{
    switch (c[0]) {
        case 'T': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        case 'A': return 14;
    }
    return c[0] - '0';
}

char suit(const std::string& c)
{
    return c[1];
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& c1, const std::string& c2, const std::string& t)
{
    if (suit(c1) == suit(c2))
        return answer(rank(c1) > rank(c2));

    answer(suit(c1) == t[0]);
}

int main()
{
    std::string t;
    std::cin >> t;

    std::string c1, c2;
    std::cin >> c1 >> c2;

    solve(c1, c2, t);

    return 0;
}

