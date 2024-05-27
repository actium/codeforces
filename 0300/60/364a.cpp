#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, unsigned a)
{
    const size_t n = s.length();

    integer f[36001] = {};
    for (size_t i = 0; i < n; ++i) {
        integer t = 0;
        for (size_t j = i; j < n; ++j) {
            t += s[j] - '0';
            ++f[t];
        }
    }

    if (a == 0)
        return answer((n * (n + 1) - f[0]) * f[0]);

    integer k = 0;
    for (unsigned i = 1; i * i <= a; ++i) {
        if (a % i != 0)
            continue;

        const size_t x = a / i;
        if (x > 36000)
            continue;

        k += f[i] * f[x] * (i != x ? 2 : 1);
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned a;
    std::cin >> a;

    std::string s;
    std::cin >> s;

    solve(s, a);

    return 0;
}
