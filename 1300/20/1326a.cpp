#include <iostream>

void no_answer()
{
    std::cout << -1 << '\n';
}

void answer(const std::string& v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    if (n == 1)
        return no_answer();

    std::string x(n, '3');
    x.front() = '2';
    answer(x);
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

