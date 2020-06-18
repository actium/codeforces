#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t count = 0;
    for (size_t i = 0; i < n; ++i) {
        size_t p, q;
        std::cin >> p >> q;

        if (q - p > 1)
            ++count;
    }

    answer(count);

    return 0;
}

