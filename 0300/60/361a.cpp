#include <iostream>

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    for (unsigned i = 0; i < n; ++i) {
        const char* separator = "";
        for (unsigned j = 0; j < n; ++j) {
            std::cout << separator << (i == j ? k : 0);
            separator = " ";
        }
        std::cout << '\n';
    }

    return 0;
}

