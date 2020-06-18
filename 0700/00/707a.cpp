#include <iostream>

void answer(bool color)
{
    constexpr const char* s[2] = { "#Black&White", "#Color" };
    std::cout << s[color] << '\n';
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    bool color = false;
    for (size_t r = 0; r < n; ++r) {
        for (size_t c = 0; c < m; ++c) {
            char p;
            std::cin >> p;

            if (p == 'C' || p == 'M' || p == 'Y')
                color = true;
        }
    }

    answer(color);

    return 0;
}

