#include <iostream>
#include <string>

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned h = 0;
    for (size_t i = 0; i < n; ) {
        if (s[i+1] == '/') {
            h -= 2;
            std::cout << std::string(h, ' ') << s.substr(i, 4) << '\n';
            i += 4;
        } else {
            std::cout << std::string(h, ' ') << s.substr(i, 3) << '\n';
            h += 2;
            i += 3;
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

