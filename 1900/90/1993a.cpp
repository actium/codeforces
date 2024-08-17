#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length() / 4;

    unsigned f[4] = {};
    for (const char c : s) {
        if (c != '?')
            ++f[c-'A'];
    }

    unsigned k = 0;
    for (size_t i = 0; i < 4; ++i)
        k += std::min<unsigned>(f[i], n);

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
