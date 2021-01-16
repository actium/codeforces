#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v % 256 << '\n';
}

void solve(const std::string& s)
{
    const auto reverse = [](char c) {
        char r = 0;
        for (size_t i = 0; i < 8; ++i) {
            r <<= 1;
            r |= c & 1;
            c >>= 1;
        }
        return r;
    };

    char x = 0;
    for (const char c : s) {
        const char y = reverse(c);
        answer(256 + x - y);
        x = y;
    }
}

int main()
{
    std::string s;
    std::getline(std::cin, s);

    solve(s);

    return 0;
}

