#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    const auto d = [&s](size_t x) {
        return s[x] - 'A';
    };

    for (size_t i = 2; i < n; ++i) {
        if ((d(i-2) + d(i-1)) % 26 != d(i))
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
