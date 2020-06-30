#include <iostream>
#include <string>
#include <unordered_map>

void answer(char x, char y)
{
    std::cout << x << y << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::unordered_map<uint16_t, size_t> f;
    for (size_t i = 0; i < n-1; ++i) {
        const uint16_t key = s[i] << 8 | s[i+1];
        ++f[key];
    }

    std::pair<uint16_t, size_t> best = { 0, 0 };
    for (const auto& x : f) {
        if (x.second > best.second)
            best = x;
    }

    answer(best.first >> 8, best.first & 0xFF);
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

