#include <iostream>

using integer = unsigned long long;

void solve(integer n)
{
    integer p[2] = { n, n };

    if (__builtin_popcountll(n) % 2 == 1) {
        std::cout << "second" << std::endl;
        std::cin >> p[0] >> p[1];
    } else {
        std::cout << "first" << std::endl;
    }

    while (p[0] != 0 && p[1] != 0) {
        n = p[__builtin_popcountll(p[0]) % 2];
        p[0] = 1ll << __builtin_clzll(1) - __builtin_clzll(n), p[1] = n ^ p[0];
        std::cout << p[0] << ' ' << p[1] << std::endl;
        std::cin >> p[0] >> p[1];
    }
}

void test_case()
{
    integer n;
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
