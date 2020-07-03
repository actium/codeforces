#include <iostream>

#include <cmath>

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

int main()
{
    int a, b;
    std::cin >> a >> b;

    size_t n;
    std::cin >> n;

    double min = 283;
    for (size_t i = 0; i < n; ++i) {
        int x, y, v;
        std::cin >> x >> y >> v;

        const double d = hypot(a - x, b - y);
        min = std::min(min, d / v);
    }

    answer(min);

    return 0;
}

