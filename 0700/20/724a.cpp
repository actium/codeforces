#include <algorithm>
#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    constexpr unsigned m[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    const std::string w[7] = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };

    const int a = std::find(std::begin(w), std::end(w), s) - std::begin(w);
    const int b = std::find(std::begin(w), std::end(w), t) - std::begin(w);

    for (size_t i = 0; i < 11; ++i) {
        if ((a + m[i] - b) % 7 == 0)
            return answer(true);
    }

    answer(false);
}

int main()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}

