#include <iostream>

char color(unsigned n, unsigned m, unsigned i, unsigned j)
{
    if (n % 2 == 0 && i == n-1 && j == 0)
        return 'B';

    if (n % 2 == 1 && m % 2 == 0 && i == 0 && j == m-1)
        return 'B';

    return (i + j) % 2 == 0 ? 'B' : 'W';
}

void solve(unsigned n, unsigned m)
{
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j)
            std::cout << color(n, m, i, j);

        std::cout << '\n';
    }
}

void test_case()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

