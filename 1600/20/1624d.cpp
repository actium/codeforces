#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s, size_t k)
{
    unsigned f[26] = {};
    for (const char c : s)
        ++f[c-'a'];

    unsigned p = 0;
    for (const unsigned x : f)
        p += x / 2;

    const unsigned q = p / k;
    answer(2 * q + (s.length() - 2 * q * k >= k));
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
