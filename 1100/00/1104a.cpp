#include <iostream>

void solve(unsigned n)
{
    std::cout << n << '\n';
    for (size_t i = 0; i < n-1; ++i)
        std::cout << "1 ";

    std::cout << "1\n";
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

