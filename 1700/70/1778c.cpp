#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::string& a, const std::string& b, unsigned k)
{
    const size_t n = a.length();

    unsigned x[26] = {};
    for (const char c : a)
        x[c-'a'] = 1;

    for (size_t i = 1; i < 26; ++i)
        x[i] += x[i-1];

    const auto check = [&](unsigned s) {
        integer r = 0;
        for (size_t i = 0, q = 0; i < n; ++i) {
            if (a[i] == b[i] || (s & 1 << x[a[i]-'a']) != 0)
                r += ++q;
            else
                q = 0;
        }
        return r;
    };

    integer r = 0;
    for (unsigned i = 0, m = 1 << x[25]; i < m; ++i) {
        if (__builtin_popcount(i) <= k)
            r = std::max(r, check(i << 1));
    }

    answer(r);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned k;
    std::cin >> k;

    std::string a, b;
    std::cin >> a >> b;

    solve(a, b, k);
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
