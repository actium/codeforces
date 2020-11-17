#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& s, unsigned c0, unsigned c1, unsigned h)
{
    unsigned f[2] = {};
    for (const char c : s)
        ++f[c - '0'];

    answer(f[0] * std::min(c0, c1 + h) + f[1] * std::min(c1, c0 + h));
}

void test_case()
{
    unsigned n, c0, c1, h;
    std::cin >> n >> c0 >> c1 >> h;

    std::string s;
    std::cin >> s;

    solve(s, c0, c1, h);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

