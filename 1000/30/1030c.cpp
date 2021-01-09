#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& a)
{
    unsigned s = 0;
    for (const char c : a)
        s += c - '0';

    if (s == 0)
        return answer(true);

    const auto check = [&](unsigned t) {
        unsigned s = 0;
        for (const char c : a) {
            s += c - '0';
            if (s > t)
                return false;

            s %= t;
        }
        return s == 0;
    };

    for (unsigned i = 2; i <= s; ++i) {
        if (s % i == 0 && check(s / i))
            return answer(true);
    }

    answer(false);
}

int main()
{
    size_t n;
    std::cin >> n;

    std::string a;
    std::cin >> a;

    solve(a);

    return 0;
}

