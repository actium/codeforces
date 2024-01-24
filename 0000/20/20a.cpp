#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    std::string t = "/";
    for (const char c : s) {
        if (c != '/' || t.back() != '/')
            t.push_back(c);
    }

    if (t.length() > 1 && t.back() == '/')
        t.pop_back();

    answer(t);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
