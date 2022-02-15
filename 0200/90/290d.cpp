#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, unsigned d)
{
    std::string t;
    for (const char c : s) {
        if (std::tolower(c) < 'a' + d)
            t.push_back(std::toupper(c));
        else
            t.push_back(std::tolower(c));
    }

    answer(t);
}

int main()
{
    std::string s;
    std::cin >> s;

    unsigned d;
    std::cin >> d;

    solve(s, d);

    return 0;
}
