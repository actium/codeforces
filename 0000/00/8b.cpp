#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "BUG", "OK" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    unsigned x = 100, y = 100, t = 0, v[200][200] = {};

    const auto check = [&] {
        return v[x][y] == 0
            && (v[x+1][y] == 0 || v[x+1][y] == t)
            && (v[x][y-1] == 0 || v[x][y-1] == t)
            && (v[x-1][y] == 0 || v[x-1][y] == t)
            && (v[x][y+1] == 0 || v[x][y+1] == t);
    };

    for (const char c : s) {
        v[x][y] = ++t;

        switch (c) {
            case 'R': ++x; break;
            case 'D': --y; break;
            case 'L': --x; break;
            case 'U': ++y; break;
        }

        if (!check())
            return answer(false);
    }

    answer(true);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
