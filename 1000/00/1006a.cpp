#include <iostream>

int main()
{
    size_t n;
    std::cin >> n;

    const char* separator = "";
    for (size_t i = 0; i < n; ++i) {
        unsigned a;
        std::cin >> a;

        std::cout << separator << ((a - 1) | 1);
        separator = " ";
    }
    std::cout << '\n';

    return 0;
}

