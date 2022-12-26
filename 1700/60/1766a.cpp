#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(const std::string& n)
{
    answer(n[0] - '0' + (n.length() - 1) * 9);
}

void test_case()
{
    std::string n;
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
