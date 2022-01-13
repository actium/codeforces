#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned a = 10, r = 1, q = 0;
    bool v[10] = {};
    for (size_t i = 0; i < n; ++i) {
        const char c = s[i];
        if (c == '?') {
            i == 0 ? r *= 9 : ++q;
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

    std::string t = std::to_string(r);
    t.append(q, '0');
    answer(t);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}

