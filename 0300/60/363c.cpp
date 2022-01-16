#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    size_t j = std::min<size_t>(n, 2);
    for (size_t i = 2; i < n; ++i) {
        if (s[i] == s[j-1] && s[i] == s[j-2])
            continue;

        if (s[i] == s[j-1] && j >= 3 && s[j-3] == s[j-2])
            continue;

        s[j++] = s[i];
    }
    s.resize(j);

    answer(s);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

