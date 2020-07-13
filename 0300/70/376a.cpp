#include <iostream>
#include <string>

void answer(int v)
{
    constexpr const char* s[3] = { "right", "balance", "left" };
    std::cout << s[v + 1] << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();
    const size_t x = s.find('^');

    unsigned long long left = 0;
    for (size_t i = 0; i < x; ++i) {
        if (isdigit(s[i]))
            left += (x - i) * (s[i] - '0');
    }

    unsigned long long right = 0;
    for (size_t i = x + 1; i < n; ++i) {
        if (isdigit(s[i]))
            right += (i - x) * (s[i] - '0');
    }

    if (left == right)
        answer(0);
    else
        answer(left < right ? -1 : 1);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

