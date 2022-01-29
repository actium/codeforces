#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    std::string t;
    for (const char c : s) {
        if (!t.empty() && t.back() == c)
            t.pop_back();
        else
            t.push_back(c);
    }

    answer(t);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
