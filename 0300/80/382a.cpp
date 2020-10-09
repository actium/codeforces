#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    std::string l, r;
    for (const char c : s) {
        if (c == '|')
            std::swap(l, r);
        else
            r.push_back(c);
    }

    for (const char c : t)
        (l.size() < r.size() ? l : r).push_back(c);

    if (l.size() == r.size())
        answer(l + '|' + r);
    else
        answer("Impossible");
}

int main()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}

