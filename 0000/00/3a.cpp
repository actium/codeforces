#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    std::cout << v.size() << '\n';

    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(std::string& s, const std::string& t)
{
    std::vector<std::string> m;
    while (s != t) {
        std::string move;

        if (s[0] < t[0]) {
            ++s[0];
            move.push_back('R');
        } else if (s[0] > t[0]) {
            --s[0];
            move.push_back('L');
        }

        if (s[1] < t[1]) {
            ++s[1];
            move.push_back('U');
        } else if (s[1] > t[1]) {
            --s[1];
            move.push_back('D');
        }

        m.push_back(move);
    }

    answer(m);
}

int main()
{
    std::string s;
    std::cin >> s;

    std::string t;
    std::cin >> t;

    solve(s, t);

    return 0;
}

