#include <iostream>

int main()
{
    unsigned n;
    std::cin >> n;

    std::cout << n;
    for (unsigned i = 1; i < n; ++i)
        std::cout << ' ' << i;

    std::cout << '\n';

    return 0;
}

