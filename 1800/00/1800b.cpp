#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, unsigned k)
{
    unsigned f[256] = {};
    for (const char c : s)
        ++f[c];

    unsigned q = 0;
    for (char x = 'A'; x <= 'Z'; ++x) {
        const char y = x - 'A' + 'a';

        const unsigned c = std::min(f[x], f[y]);
        const unsigned d = std::min(k, (f[x] + f[y] - 2 * c) / 2);
        q += c + d;
        k -= d;
    }

    answer(q);
}

void test_case()
{
    unsigned n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    solve(s, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
