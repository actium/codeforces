#include <iostream>
#include <string>

void answer(double v)
{
    std::cout.precision(9);

    std::cout << v << '\n';
}

unsigned C(int n, int r)
{
    if (n < 0 || r < 0)
        return 0;

    if (n == r)
        return 1;

    return C(n - 1, r) + C(n - 1, r - 1);
}

void solve(const std::string& s1, const std::string& s2)
{
    unsigned f[2][3] = {};

    const auto c = [&](const std::string& s, size_t i) {
        for (const char c : s) {
            if (c == '+')
                ++f[i][0];

            if (c == '-')
                ++f[i][1];

            if (c == '?')
                ++f[i][2];
        }
    };

    c(s1, 0);
    c(s2, 1);

    if (f[1][0] > f[0][0] || f[1][1] > f[0][1])
        return answer(0);

    answer(C(f[1][2], f[0][0] - f[1][0]) / double(1 << f[1][2]));
}

int main()
{
    std::string s1;
    std::cin >> s1;

    std::string s2;
    std::cin >> s2;

    solve(s1, s2);

    return 0;
}

