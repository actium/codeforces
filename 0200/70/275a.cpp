#include <iostream>

void press(unsigned table[3][3], size_t r, size_t c, size_t count)
{
    if (count % 2 == 0)
        return;

    table[r][c] ^= 1;

    if (r > 0)
        table[r-1][c] ^= 1;
    if (r < 2)
        table[r+1][c] ^= 1;
    if (c > 0)
        table[r][c-1] ^= 1;
    if (c < 2)
        table[r][c+1] ^= 1;
}

int main()
{
    unsigned table[3][3] = { { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 } };

    for (size_t r = 0; r < 3; ++r) {
        for (size_t c = 0; c < 3; ++c) {
            unsigned count;
            std::cin >> count;

            press(table, r, c, count);
        }
    }

    for (size_t r = 0; r < 3; ++r) {
        for (size_t c = 0; c < 3; ++c)
            std::cout << table[r][c];

        std::cout << '\n';
    }

    return 0;
}

