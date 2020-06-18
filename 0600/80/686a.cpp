#include <iostream>

void answer(long long x, size_t y)
{
    std::cout << x << ' ' << y << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    long long x;
    std::cin >> x;

    size_t c = 0;
    while (n-- > 0) {
        char t;
        std::cin >> t;

        size_t d;
        std::cin >> d;

        if (t == '+') {
            x += d;
            continue;
        }

        if (d <= x)
            x -= d;
        else
            ++c;
    }

    answer(x, c);

    return 0;
}

