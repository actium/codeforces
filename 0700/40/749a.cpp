#include <iostream>

void solve(unsigned n)
{
    std::cout << (n / 2) << '\n';

    std::cout << (2 + n % 2);
    for (size_t i = 1; i < n / 2; ++i)
        std::cout << " 2";

    std::cout << '\n';
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

