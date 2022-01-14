#include <iostream>
#include <string>

void answer(unsigned x, const std::string& y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void solve(std::string& s)
{
    const size_t n = s.length();

    unsigned k = 0;

    s.push_back('R');
    for (size_t i = 1; i < n; ++i) {
        if (s[i] != s[i-1])
            continue;

        if (s[i] == s[i+1])
            s[i] = (s[i] == 'R' ? 'G' : 'R');
        else
            s[i] ^= 'R' ^ 'G' ^ 'B' ^ s[i+1];

        ++k;
    }
    s.pop_back();

    answer(k, s);
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
