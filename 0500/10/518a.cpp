#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << "No such string" << '\n';
}

void solve(std::string& s, const std::string& t)
{
    auto it = s.rbegin();
    while (it != s.rend() && *it == 'z')
        *it++ = 'a';

    ++*it;

    s < t ? answer(s) : no_answer();
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}
