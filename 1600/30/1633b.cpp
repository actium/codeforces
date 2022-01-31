#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    unsigned f[2] = {};
    for (const char c : s)
        ++f[c-'0'];

    if (f[0] > f[1])
        return answer(f[1]);

    if (f[1] > f[0])
        return answer(f[0]);

    answer(f[0] > 0 ? f[0] - 1 : 0);
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
