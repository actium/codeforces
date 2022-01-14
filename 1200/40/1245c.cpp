#include <iostream>
#include <string>
#include <utility>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    constexpr unsigned M = 1000000007;

    const auto f = [M](unsigned x) {
        unsigned a = 1, b = 1;
        while (x-- > 0)
            a = std::exchange(b, (a + b) % M);

        return a;
    };

    unsigned k = 1, u = 0, n = 0;
    for (const char c : s) {
        if (c == 'm' || c == 'w')
            return answer(0);

        if (c == 'u') {
            ++u;
        } else {
            k = 1ull * k * f(u) % M;
            u = 0;
        }

        if (c == 'n') {
            ++n;
        } else {
            k = 1ull * k * f(n) % M;
            n = 0;
        }
    }

    answer(k);
}

int main()
{
    std::string s;
    std::cin >> s;

    solve(s + ' ');

    return 0;
}
