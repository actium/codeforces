#include <iostream>

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned max_a = 0;
    for (size_t i = 0; i < n; ++i) {
        unsigned a;
        std::cin >> a;

        max_a = std::max(max_a, a);
    }

    size_t m;
    std::cin >> m;

    unsigned max_b = 0;
    for (size_t i = 0; i < m; ++i) {
        unsigned b;
        std::cin >> b;

        max_b = std::max(max_b, b);
    }

    answer(max_a, max_b);

    return 0;
}

