#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

int main()
{
    int r = 0, c = 0;
    for (size_t i = 1; i <= 5; ++i) {
        for (size_t j = 1; j <= 5; ++j) {
            unsigned x;
            std::cin >> x;

            if (x == 1)
                r = i, c = j;
        }
    }

    answer(abs(3 - r) + abs(3 - c));

    return 0;
}

