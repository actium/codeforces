#include <iostream>
#include <string>

void answer(const std::string& x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, size_t k)
{
    const size_t n = s.length(), q = n / k;

    unsigned f[26] = {};
    for (const char c : s)
        ++f[c - 'a'];

    std::string t(k, 'a');
    for (size_t i = 0; i < k; ++i) {
        for (size_t j = 0; j < q && f[j] != 0; ++j) {
            --f[j];
            ++t[i];
        }
    }

    answer(t);
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
