#include <iostream>
#include <string>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    unsigned f[2] = {};
    for (const char c : s)
        ++f[c=='_'];

    const integer a = f[0] / 2, b = f[0] - a;

    answer(a * f[1] * b);
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
