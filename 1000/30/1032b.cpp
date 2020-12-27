#include <iostream>
#include <string>

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned r = 1;
    while ((n + r - 1) / r > 20)
        ++r;

    const unsigned c = (n + r - 1) / r, k = c * r % n;
    std::cout << r << ' ' << c << '\n';

    for (size_t i = 0, j = 0; i < r; ++i) {
        if (i < k) {
            std::cout << s.substr(j, c - 1) << '*' << '\n';
            j += c - 1;
        } else {
            std::cout << s.substr(j, c) << '\n';
            j += c;
        }
    }
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

