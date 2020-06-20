#include <iostream>
#include <string>

int main()
{
    size_t n;
    std::cin >> n;

    size_t i = 1;
    for (; i <= n / 2; ++i) {
        std::string row(n, '*');
        for (size_t j = n / 2 - i + 1; j < n / 2 + i; ++j)
            row[j] = 'D';

        std::cout << row << '\n';
    }
    std::cout << std::string(n, 'D') << '\n';
    for (; i < n; ++i) {
        std::string row(n, '*');
        for (size_t j = i - n / 2; j < 3 * n / 2 - i; ++j)
            row[j] = 'D';

        std::cout << row << '\n';
    }

    return 0;
}

