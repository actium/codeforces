#include <iostream>
#include <string>

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(size_t n)
{
    std::string s(n/2, '1');
    if (n % 2 != 0)
        s[0] = '7';

    answer(s);
}

void test_case()
{
    size_t n;
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

