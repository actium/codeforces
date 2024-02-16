#include <iostream>

void solve(unsigned n)
{
    if (n > 5) {
        for (unsigned i = 2; i <= 4; ++i)
            std::cout << 1 << ' ' << i << '\n';

        for (unsigned i = 5; i <= n; ++i)
            std::cout << 2 << ' ' << i << '\n';
    } else {
        std::cout << -1 << '\n';
    }

    for (unsigned i = 2; i <= n; ++i)
        std::cout << i-1 << ' ' << i << '\n';
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
