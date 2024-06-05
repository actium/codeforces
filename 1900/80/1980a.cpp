#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, unsigned m)
{
    unsigned f[7] = {};
    for (const char c : s)
        ++f[c-'A'];

    unsigned k = 0;
    for (size_t i = 0; i < 7; ++i) {
        if (f[i] < m)
            k += m - f[i];
    }

    answer(k);
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    solve(s, m);
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
