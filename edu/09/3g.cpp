#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

using integer = unsigned long long;

void solve(const std::string& s, integer c)
{
    const size_t n = s.length();

    integer a = 0, b = 0, d = 0, k = 0;
    for (size_t i = 0, j = 0; j < n; ++j) {
        if (s[j] == 'a')
            ++a;

        if (s[j] == 'b')
            ++b, d += a;

        for ( ; d > c; ++i) {
            if (s[i] == 'a')
                --a, d -= b;

            if (s[i] == 'b')
                --b;
        }

        k = std::max<unsigned>(k, j - i + 1);
    }

    answer(k);
}

int main()
{
    size_t n;
    std::cin >> n;

    integer c;
    std::cin >> c;

    std::string s;
    std::cin >> s;

    solve(s, c);

    return 0;
}

