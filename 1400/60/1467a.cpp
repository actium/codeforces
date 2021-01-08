#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    std::string s(n, '9');
    for (size_t i = 1; i < n; ++i)
        s[i] = '0' + (i + 7) % 10;

    answer(s);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

