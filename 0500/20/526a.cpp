#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "no", "yes" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    const auto check = [&](size_t x, size_t d) {
        unsigned k = 0;
        for (size_t i = x; i < n && s[i] == '*'; i += d)
            ++k;

        return k >= 5;
    };

    for (size_t d = 1; d < n; ++d) {
        for (size_t i = 0; i < n; ++i) {
            if (check(i, d))
                return answer(true);
        }
    }

    answer(false);
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

