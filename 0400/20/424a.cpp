#include <algorithm>
#include <iostream>
#include <string>

void answer(unsigned x, const std::string& y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    const unsigned k = std::count(s.begin(), s.end(), 'X');
    if (k > n/2) {
        const unsigned c = k - n/2;
        for (size_t i = 0, j = 0; i < n && j < c; ++i) {
            if (s[i] == 'X')
                s[i] = 'x', ++j;
        }
        answer(c, s);
    } else {
        const unsigned c = n/2 - k;
        for (size_t i = 0, j = 0; i < n && j < c; ++i) {
            if (s[i] == 'x')
                s[i] = 'X', ++j;
        }
        answer(c, s);
    }
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

