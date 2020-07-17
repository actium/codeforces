#include <iostream>
#include <string>

bool vowel(char c)
{
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned d = 0, k = 0;
    for (size_t i = 0; i < n; ++i) {
        ++d;

        if (vowel(s[i])) {
            k = std::max(k, d);
            d = 0;
        }
    }

    answer(std::max(k, d+1));
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

