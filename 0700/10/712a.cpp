#include <iostream>

int main()
{
    size_t n;
    std::cin >> n;

    int last;
    std::cin >> last;
    for (size_t i = 1; i < n; ++i) {
        int a;
        std::cin >> a;

        std::cout << last + a << ' ';
        last = a;
    }
    std::cout << last << '\n';

    return 0;
}

