#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    const size_t n = s.length();

    int f[256] = {};
    for (const char c : t)
        ++f[c];

    integer k = 0;
    for (size_t i = 0, j = 0; j < n; ++j) {
        for (--f[s[j]]; i <= j && f[s[j]] < 0; ++i)
            ++f[s[i]];

        k += j - i + 1;
    }

    answer(k);
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}

