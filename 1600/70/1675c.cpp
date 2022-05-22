#include <iostream>
#include <string>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& s)
{
    const size_t n = s.length();

    size_t z = s.find('0');
    if (z == std::string::npos)
        z = n - 1;

    size_t o = s.rfind('1');
    if (o == std::string::npos)
        o = 0;

    answer(z - o + 1);
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
