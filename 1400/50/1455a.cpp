#include <iostream>
#include <string>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(const std::string& n)
{
    answer(n.length());
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

