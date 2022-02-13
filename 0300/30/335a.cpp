#include <iostream>
#include <string>

void answer(unsigned x, const std::string& y)
{
    std::cout << x << '\n';
    std::cout << y << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s, unsigned n)
{
    unsigned f[26] = {}, q[26] = {};
    for (const char c : s) {
        const size_t i = c - 'a';
        ++f[i];
        q[i] = 1;
    }

    std::string p;
    for (size_t i = 0; i < 26; ++i)
        p += std::string(q[i], 'a' + i);

    if (p.length() > n)
        return no_answer();

    while (p.length() < n) {
        size_t x = p[0] - 'a';
        for (size_t i = 0; i < 26; ++i) {
            if (f[i] * q[x] > f[x] * q[i])
                x = i;
        }
        p.push_back('a' + x);
        ++q[x];
    }

    unsigned k = 0;
    for (const char c : p) {
        const size_t i = c - 'a';
        k = std::max(k, (f[i] + q[i] - 1) / q[i]);
    }

    answer(k, p);
}

int main()
{
    std::string s;
    std::cin >> s;

    unsigned n;
    std::cin >> n;

    solve(s, n);

    return 0;
}
