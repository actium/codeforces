#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length() / 2;

    size_t c[2] = {};
    for (size_t i = 0; i < n; ++i) {
        if (s[i] != '4' && s[i] != '7' || s[n+i] != '4' && s[n+i] != '7')
            return answer(false);

        c[0] += s[i];
        c[1] += s[n+i];
    }

    answer(c[0] == c[1]);
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

