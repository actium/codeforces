#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    std::string u;
    for (const char c : s) {
        if (!u.empty() && c >= t.front())
            break;

        u.push_back(c);
    }
    u.push_back(t.front());

    answer(u);
}

int main()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}

