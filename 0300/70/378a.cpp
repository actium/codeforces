#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;

    size_t f[3] = {};
    for (int i = 1; i <= 6; ++i) {
        const int da = abs(i - a);
        const int db = abs(i - b);
        if (da < db)
            ++f[0];
        else if (da == db)
            ++f[1];
        else
            ++f[2];
    }

    std::cout << f[0] << ' ' << f[1] << ' ' << f[2] << '\n';

    return 0;
}

