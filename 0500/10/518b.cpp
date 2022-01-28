#include <iostream>
#include <string>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::string& s, const std::string& t)
{
    unsigned fs[64] = {};
    for (const char c : s)
        ++fs[c-'A'];

    unsigned ft[64] = {};
    for (const char c : t)
        ++ft[c-'A'];

    unsigned h = 0;
    for (size_t i = 0; i < 64; ++i) {
        const unsigned k = std::min(fs[i], ft[i]);
        h += k;
        fs[i] -= k;
        ft[i] -= k;
    }

    unsigned o = 0;
    for (size_t i = 0; i < 64; ++i) {
        const unsigned k = std::min(fs[i], ft[i^32]);
        o += k;
        fs[i] -= k;
        ft[i^32] -= k;
    }

    answer(h, o);
}

int main()
{
    std::string s, t;
    std::cin >> s >> t;

    solve(s, t);

    return 0;
}
