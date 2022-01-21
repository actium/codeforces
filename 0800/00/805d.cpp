#include <iostream>
#include <string>

constexpr unsigned M = 1000000007;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned raise(unsigned p)
{
    unsigned r = 1;
    for (unsigned long long b = 2; p != 0; p /= 2) {
        if (p & 1)
            r = r * b % M;

        b = b * b % M;
    }
    return r;
}

void solve(const std::string& s)
{
    unsigned a = 0, k = 0;
    for (const char c : s) {
        if (c == 'a')
            ++a;
        else
            k = (k + raise(a) - 1) % M;
    }

    answer(k);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s);

    return 0;
}
