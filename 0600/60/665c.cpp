#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    s.push_back(' ');
    for (size_t i = 1; i < n; ++i) {
        if (s[i] != s[i-1])
            continue;

        while (s[i] == s[i-1] || s[i] == s[i+1])
            s[i] += (s[i] < 'z' ? 1 : -25);
    }
    s.pop_back();

    answer(s);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

