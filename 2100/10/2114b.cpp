#include <iostream>
#include <string>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& s, unsigned k)
{
    unsigned f[2] = {};
    for (const char c : s)
        ++f[c-'0'];

    const unsigned lb = std::max(f[0], f[1]) - s.size() / 2, ub = f[0] / 2 + f[1] / 2;
    answer(lb <= k && k <= ub && (k - lb) % 2 == 0);
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
