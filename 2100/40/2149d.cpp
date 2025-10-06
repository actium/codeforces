#include <iostream>
#include <string>
#include <vector>

using integer = unsigned long long;

constexpr integer oo = ~integer(0);

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    std::vector<size_t> p[2];
    for (size_t i = 0; i < n; ++i)
        p[s[i]-'a'].push_back(i);

    integer k = oo;
    for (size_t i = 0; i < 2; ++i) {
        const size_t m = p[i].size(), x = m / 2;

        integer d = 0;
        for (size_t j = 0; j < x; ++j)
            d += (p[i][x] - p[i][j]) - (x - j);
        for (size_t j = x; j < m; ++j)
            d += (p[i][j] - p[i][x]) - (j - x);

        k = std::min(k, d);
    }

    answer(k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    solve(s);
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
