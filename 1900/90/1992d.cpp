#include <iostream>
#include <string>
#include <vector>

constexpr unsigned oo = ~0u;

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(const std::string& a, unsigned m, unsigned k)
{
    const size_t n = a.length();

    std::vector<unsigned> t(n, oo);
    t[0] = 0;
    for (size_t i = 1; i < n; ++i) {
        if (a[i] == 'C')
            continue;

        if (t[i-1] != oo)
            t[i] = t[i-1] + (a[i] == 'W');

        for (unsigned d = 2; d <= m && d <= i; ++d) {
            if (a[i-d] == 'L' && t[i-d] != oo)
                t[i] = std::min(t[i], t[i-d] + (a[i] == 'W'));
        }
    }

    answer(t[n-1] <= k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m, k;
    std::cin >> m >> k;

    std::string a;
    std::cin >> a;

    solve('L' + a + 'L', m, k);
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
