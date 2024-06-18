#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned ta, unsigned b, unsigned tb, const std::string& s)
{
    const unsigned st = ((s[0] - '0') * 10 + s[1] - '0') * 60 + (s[3] - '0') * 10 + (s[4] - '0');

    unsigned k = 0;
    for (unsigned t = 300; t < 1440; t += b) {
        if (t < st + ta && t + tb > st)
            ++k;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned a, ta;
    std::cin >> a >> ta;

    unsigned b, tb;
    std::cin >> b >> tb;

    std::string s;
    std::cin >> s;

    solve(ta, b, tb, s);

    return 0;
}
