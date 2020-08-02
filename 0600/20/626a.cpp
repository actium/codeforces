#include <iostream>
#include <string>

std::pair<int, int> execute(int x, int y, const std::string& p)
{
    for (const char c : p) {
        switch (c) {
            case 'U':
                ++y;
                break;
            case 'D':
                --y;
                break;
            case 'R':
                ++x;
                break;
            case 'L':
                --x;
                break;
        }
    }
    return { x, y };
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned k = 0;

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i; j < n; ++j) {
            const std::pair<int, int> p = execute(0, 0, s.substr(i, j - i + 1));
            if (p.first == 0 && p.second == 0)
                ++k;
        }
    }

    answer(k);
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

