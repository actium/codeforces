#include <algorithm>
#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(const std::string& s)
{
    unsigned f[10] = {};
    for (const char c : s)
        ++f[c - '0'];

    std::sort(std::begin(f), std::end(f), std::greater<unsigned>());

    if (f[0] == 4)
        return no_answer();

    answer(f[0] == 3 ? 6 : 4);
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
