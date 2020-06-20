#include <iostream>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    int x = 0, y = 0, z = 0;
    for (size_t i = 0; i < n; ++i) {
        int dx, dy, dz;
        std::cin >> dx >> dy >> dz;

        x += dx, y += dy, z += dz;
    }

    answer(x == 0 && y == 0 && z == 0);

    return 0;
}

