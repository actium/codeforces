#include <iostream>

void solve(unsigned a)
{
    std::cout << 2 * a - 1 << ' ' << 2 << '\n';
    std::cout << 1 << ' ' << 2 << '\n';
}

int main()
{
    unsigned a;
    std::cin >> a;

    solve(a);

    return 0;
}
