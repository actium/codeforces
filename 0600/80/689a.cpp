#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    constexpr std::pair<size_t, size_t> p[10] = {
        { 3, 1 }, { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 0 },
        { 1, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 }, { 2, 2 }
    };

    const size_t n = s.length();

    const auto check = [&](size_t r, size_t c) {
        for (size_t i = 1; i < n; ++i) {
            r += p[s[i]-'0'].first - p[s[i-1]-'0'].first;
            c += p[s[i]-'0'].second - p[s[i-1]-'0'].second;

            if (r > 3 || c > 2 || r == 3 && c != 1)
                return 0;
        }
        return 1;
    };

    unsigned k = check(3, 1);
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j)
            k += check(i, j);
    }

    answer(k == 1);
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
