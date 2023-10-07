#include <iostream>
#include <string>

constexpr unsigned M = 998244353;

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    unsigned long long c = 0, k = 1;
    for (size_t i = 0, j = 0; i < n; i = j) {
        while (j < n && s[j] == s[i])
            ++j;

        c += (j - i - 1);
        k = k * (j - i) % M;
    }

    for (unsigned i = 2; i <= c; ++i)
        k = k * i % M;

    answer(c, k);
}

void test_case()
{
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
