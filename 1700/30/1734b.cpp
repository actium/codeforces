#include <iostream>

void solve(unsigned n)
{
    for (unsigned i = 0; i < n; ++i) {
        for (unsigned j = 0; j <= i; ++j)
            std::cout << (j == 0 || j == i ? '1' : '0') << ' ';

        std::cout << '\n';
    }
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
