#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

integer sum(unsigned n)
{
    return n * (n + 1ull) / 2;
}

void solve(const std::string& s, unsigned k)
{
    unsigned f[2] = {};
    for (const char c : s)
        ++f[c-'0'];

    if (f[0] > f[1])
        std::swap(f[0], f[1]);

    const unsigned d = std::min(f[0], k);
    answer(sum(f[0] - d) + sum(f[1] + d) + 1);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);
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
