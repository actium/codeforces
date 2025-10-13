#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, const std::string& s)
{
    unsigned f[3] = {};
    for (const char c : s)
        ++f[c-'0'];

    std::string r(n, "+-"[s.length() == n]);
    {
        for (size_t i = 0; i < f[0]; ++i)
            r[i] = '-';

        for (size_t i = 0; i < f[1]; ++i)
            r[n-1-i] = '-';

        for (size_t i = 0; i < f[2]; ++i) {
            if (r[f[0]+i] == '+')
                r[f[0]+i] = '?';

            if (r[n-1-f[1]-i] == '+')
                r[n-1-f[1]-i] = '?';
        }
    }

    answer(r);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    size_t k;
    std::cin >> k;

    std::string s;
    std::cin >> s;

    solve(n, s);
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
