#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned c = 0;

    int b = 0;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == 'R' && ++b == 1 && i > 0 && s[i-1] == 'R')
            ++c;

        if (s[i] == 'U' && --b == -1 && i > 0 && s[i-1] == 'U')
            ++c;
    }

    answer(c);
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

