#include <array>
#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& p, const std::string& h)
{
    const size_t n = p.length();
    const size_t m = h.length();

    if (m < n)
        return answer(false);

    std::array<unsigned, 26> f = {};
    for (const char c : p)
        ++f[c - 'a'];

    for (size_t i = 0; i <= m - n; ++i) {
        std::array<unsigned, 26> g = {};
        for (size_t j = 0; j < n; ++j) {
            const size_t key = h[i + j] - 'a';
            ++g[key];
        }

        if (g == f)
            return answer(true);
    }

    answer(false);
}

void test_case()
{
    std::string p;
    std::cin >> p;

    std::string h;
    std::cin >> h;

    solve(p, h);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

