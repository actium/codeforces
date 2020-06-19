#include <iostream>

int main()
{
    unsigned n;
    std::cin >> n;

    unsigned x = 1, y = 1;
    for (size_t i = 1; i <= n; ++i) {
        if (i == x || i == y)
            std::cout << 'O';
        else
            std::cout << 'o';

        if (i == y) {
            x += y;
            std::swap(x, y);
        }
    }
    std::cout << '\n';

    return 0;
}

