#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    unsigned f[26] = {};
    for (const char c : s)
        ++f[c - 'a'];

    unsigned k1 = 0, k2 = 0;
    for (const auto x : f) {
        k1 += (x == 1);
        k2 += (x > 1);
    }

    answer(k2 + k1 / 2);
}

void test_case()
{
    std::string s;
    std::cin >> s;

    solve(s);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
