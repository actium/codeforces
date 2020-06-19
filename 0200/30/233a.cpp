#include <iostream>

void solve(size_t n)
{
    if (n % 2 != 0) {
        std::cout << -1 << '\n';
        return;
    }

    while (n > 1)
        std::cout << n-- << ' ';

    std::cout << n << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}

