#include <iostream>

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned total = 0;
    for (size_t i = 0; i < n; ++i) {
        unsigned p;
        std::cin >> p;

        total += p;
    }

    answer(double(total) / n);

    return 0;
}

