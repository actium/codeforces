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

    unsigned f[3] = {};
    for (size_t i = 0, c = 0; c < 3; ++c) {
        while (i < n && s[i] == 'a' + c) {
            ++f[c];
            ++i;
        }
    }

    if (f[0] + f[1] + f[2] != n)
        return answer(false);

    if (f[0] == 0 || f[1] == 0)
        return answer(false);

    answer(f[2] == f[0] || f[2] == f[1]);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

