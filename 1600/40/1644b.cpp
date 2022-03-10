#include <iostream>

void solve(unsigned n)
{
    for (unsigned i = 1; i <= n; ++i) {
        std::cout << i;
        for (unsigned j = n; j > 0; --j) {
            if (j != i)
                std::cout << ' ' << j;
        }
        std::cout << '\n';
    }
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
