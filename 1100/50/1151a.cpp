#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    constexpr char pattern[] = "ACTG";

    const size_t n = s.length();

    unsigned c = 100;
    for (size_t i = 0; i < n-3; ++i) {
        unsigned v = 0;
        for (size_t j = 0; j < 4; ++j) {
            const unsigned d = s[i+j] < pattern[j] ? pattern[j] - s[i+j] : s[i+j] - pattern[j];
            v += std::min(d, 26 - d);
        }

        c = std::min(c, v);
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

