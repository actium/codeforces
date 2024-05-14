#include <algorithm>
#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(std::string& s)
{
    const auto evaluate = [&](size_t x) {
        std::sort(s.begin() + x, s.begin() + x + 3);

        unsigned v = 0;
        for (size_t i = 0; i < 3; ++i)
            v += s[x+i] - '0';

        return v;
    };

    unsigned p = evaluate(0), q = evaluate(3);
    if (p > q) {
        for (size_t i = 0; i < 3; ++i)
            std::swap(s[i], s[i+3]);

        std::swap(p, q);
    }

    unsigned k = 0;
    for (size_t i = 0, j = 5; p < q; ++k) {
        if ('9' - s[i] > s[j] - '0') {
            p += '9' - s[i];
            ++i;
        } else {
            q -= s[j] - '0';
            --j;
        }
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
