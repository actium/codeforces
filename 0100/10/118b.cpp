#include <iostream>
#include <string>

void print_row(size_t r, size_t n)
{
    std::cout << std::string(2 * (n - r), ' ');

    for (size_t x = 0; x < r; ++x)
        std::cout << x << ' ';

    std::cout << r;

    for (size_t x = r; x-- > 0; )
        std::cout << ' ' << x;

    std::cout << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    for (size_t r = 0; r <= n; ++r)
        print_row(r, n);

    for (size_t r = n; r-- > 0; )
        print_row(r, n);

    return 0;
}

