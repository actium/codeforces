#include <algorithm>
#include <iostream>

void answer(size_t v)
{
    constexpr const char* s[3] = { "undefined", "cw", "ccw" };
    std::cout << s[v] << '\n';
}

void solve(char s, char f, unsigned n)
{
    constexpr char p[4] = { '^', '>', 'v', '<' };

    const size_t b = std::find(std::begin(p), std::end(p), s) - std::begin(p);
    const size_t k = n % 4;

    const char cw = p[(b + k) % 4];
    const char ccw = p[(4 + b - k) % 4];

    if (f == cw && f == ccw)
        return answer(0);

    answer(f == cw ? 1 : 2);
}

int main()
{
    char s, f;
    std::cin >> s >> f;

    unsigned n;
    std::cin >> n;

    solve(s, f, n);

    return 0;
}

