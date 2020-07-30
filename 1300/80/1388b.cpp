#include <iostream>
#include <string>

void solve(unsigned n)
{
    const unsigned k = (n - 1) / 4 + 1;

    std::cout << std::string(n - k, '9') << std::string(k, '8') << '\n';
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

