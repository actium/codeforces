#include <iostream>

void solve(unsigned x, unsigned y, unsigned k)
{
    unsigned d = 0;
    while (2 * d * d < k * k)
        ++d;

    std::cout << 0 << ' ' << 0 << ' ' << d << ' ' << d << '\n';
    std::cout << d << ' ' << 0 << ' ' << 0 << ' ' << d << '\n';
}

void test_case()
{
    unsigned x, y, k;
    std::cin >> x >> y >> k;

    solve(x, y, k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
