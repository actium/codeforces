#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    int x = 0, y = 0;
    for (const char c : s) {
        switch (c) {
            case 'U': ++y; break;
            case 'D': --y; break;
            case 'R': ++x; break;
            case 'L': --x; break;
        }
    }

    answer(s.length() - std::abs(x) - std::abs(y));
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

