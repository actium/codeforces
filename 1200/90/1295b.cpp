#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void infinity()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s, int x)
{
    const size_t n = s.length();

    unsigned f[2] = {};
    for (const char c : s)
        ++f[c-'0'];

    integer k = 0;
    {
        int b = 0, d = f[0] - f[1];
        for (size_t i = 0; i < n; ++i) {
            if (d == 0 && b == x)
                return infinity();

            if (d != 0 && std::abs(x - b) % std::abs(d) == 0 && (x - b) / d >= 0)
                ++k;

            b += (s[i] == '0' ? 1 : -1);
        }
    }
    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    int x;
    std::cin >> x;

    std::string s;
    std::cin >> s;

    solve(s, x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
