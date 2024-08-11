#include <iostream>

constexpr unsigned x = (1 << 18) - 1;

void solve(unsigned k)
{
    const unsigned c = ~k & x;

    std::cout << 3 << ' ' << 3 << '\n';

    std::cout << x << ' ' << x << ' ' << c << '\n';
    std::cout << x << ' ' << k << ' ' << x << '\n';
    std::cout << c << ' ' << x << ' ' << k << '\n';
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned k;
    std::cin >> k;

    solve(k);

    return 0;
}
