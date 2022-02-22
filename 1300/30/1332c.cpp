#include <iostream>
#include <string>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, size_t k)
{
    const size_t n = s.length();

    std::vector<std::vector<unsigned>> f(n, std::vector<unsigned>(26));
    for (size_t i = 0; i < n; ++i)
        ++f[i%k][s[i]-'a'];

    unsigned q = 0;
    for (size_t i = 0; i < k; ++i) {
        unsigned c = 0, d = 0;
        for (size_t j = 0; j < 26; ++j) {
            c += f[i][j] + f[k-1-i][j];
            d = std::max(d, f[i][j] + f[k-1-i][j]);
        }

        q += c - d;
    }

    answer(q / 2);
}

void test_case()
{
    size_t n, k;
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
