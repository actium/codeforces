#include <array>
#include <iostream>
#include <string>

void answer(const std::array<std::string, 11>& v)
{
    for (const std::string& x : v)
        std::cout << x << '\n';
}

void solve(std::array<std::string, 11>& b, unsigned x, unsigned y)
{
    const unsigned r = (x - 1) % 3, c = (y - 1) % 3;

    unsigned k = 0;
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            if (b[r * 4 + i][c * 4 + j] == '.') {
                b[r * 4 + i][c * 4 + j] = '!';
                ++k;
            }
        }
    }

    if (k == 0) {
        for (size_t i = 0; i < 11; ++i) {
            for (size_t j = 0; j < 11; ++j) {
                if (b[i][j] == '.')
                    b[i][j] = '!';
            }
        }
    }

    answer(b);
}

int main()
{
    std::array<std::string, 11> b;
    for (std::string& x : b)
        std::getline(std::cin, x);

    unsigned x, y;
    std::cin >> x >> y;

    solve(b, x, y);

    return 0;
}
