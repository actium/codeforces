#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned a = 10, r = 1;
    bool v[10] = {};
    for (size_t i = 0; i < n; ++i) {
        const char c = s[i];
        if (c == '?') {
            r *= 10 - (i == 0);
            continue;
        }
        if (isalpha(c)) {
            const size_t x = c - 'A';
            if (!v[x]) {
                r *= a - (i == 0);
                --a;
                v[x] = true;
            }
        }
    }

    answer(r);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

