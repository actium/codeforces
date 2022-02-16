#include <iostream>
#include <string>
#include <vector>

void answer(const std::vector<std::string>& v)
{
    for (const std::string x : v)
        std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    size_t w = 0, d = 0;
    for (size_t i = 0, b = 0; i < n; ++i) {
        if (s[i] == '[') {
            ++w;
            d = std::max(d, ++b);
        } else {
            w += (s[i-1] == ']' ? 1 : 4);
            --b;
        }
    }

    const size_t h = d * 2 + 1;

    std::vector<std::string> p(h, std::string(w, ' '));
    for (size_t i = 0, j = 0, d = 0; i < n; ++i) {
        if (s[i] == '[') {
            if (i > 0 && s[i-1] == ']')
                ++j;

            size_t r = d++;
            p[r][j++] = '+';
            p[r][j--] = '-';
            while (++r < h - d)
                p[r][j] = '|';
            p[r][j++] = '+';
            p[r][j] = '-';
        } else {
            if (s[i-1] == '[')
                j += 2;

            size_t r = --d;
            p[r][j++] = '-';
            p[r][j] = '+';
            while (++r < h - 1 - d)
                p[r][j] = '|';
            p[r][j--] = '+';
            p[r][j++] = '-';
        }
    }

    answer(p);
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
