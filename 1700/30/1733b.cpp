#include <iostream>

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned n, unsigned x, unsigned y)
{
    if (x < y)
        std::swap(x, y);
    
    if (x == 0 || y != 0 || (n - 1) % x != 0)
        return no_answer();

    for (unsigned i = 2; i <= n; i += x) {
        for (unsigned k = 0; k < x; ++k)
            std::cout << i << ' ';
    }
    std::cout << '\n';
}

void test_case()
{
    unsigned n, x, y;
    std::cin >> n >> x >> y;

    solve(n, x, y);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
