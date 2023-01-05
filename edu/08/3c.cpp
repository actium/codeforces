#include <iostream>

void solve(unsigned d1, unsigned d2)
{
    if (d1 != d2) {
        std::cout << "NO" << '\n';
    } else {
        std::cout << "YES" << '\n';
        std::cout << d1 << ' ' << d1 * d1 << '\n';
        for (unsigned i = 1; i <= d1; ++i) {
            for (unsigned j = 1; j <= d1; ++j)
                std::cout << i << ' ' << j << '\n';
        }
    }
}

void test_case()
{
    unsigned d1, d2;
    std::cin >> d1 >> d2;

    solve(d1, d2);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
