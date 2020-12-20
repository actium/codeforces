#include <iostream>
#include <vector>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, unsigned x, unsigned y)
{
    const size_t n = s.length();

    std::vector<integer> f[3];
    for (size_t i = 0; i < 3; ++i)
        f[i].resize(1+n);

    for (size_t i = 0; i < n; ++i) {
        f[0][i+1] = f[0][i] + (s[i] == '0');
        f[1][i+1] = f[1][i] + (s[i] == '1');
        f[2][i+1] = f[2][i] + (s[i] == '?');
    }

    integer b = 0;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '0')
            b += (f[1][i] + f[2][i]) * y;
        else
            b += f[0][i] * x;
    }

    integer v = b;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '?') {
            b -= (f[0][i] + f[2][i]) * x;
            b -= (f[0].back() - f[0][i]) * y;
            b += f[1][i] * y;
            b += (f[1].back() - f[1][i] + f[2].back() - f[2][i+1]) * x;

            v = std::min(v, b);
        }
    }
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '?') {
            b -= (f[1][i] + f[2][i]) * y;
            b -= (f[1].back() - f[1][i]) * x;
            b += f[0][i] * x;
            b += (f[0].back() - f[0][i] + f[2].back() - f[2][i+1]) * y;

            v = std::min(v, b);
        }
    }

    answer(v);
}

int main()
{
    std::string s;
    std::cin >> s;

    unsigned x, y;
    std::cin >> x >> y;

    solve(s, x, y);

    return 0;
}

