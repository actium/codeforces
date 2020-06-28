#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n, b, d;
    std::cin >> n >> b >> d;

    size_t c = 0, t = 0;
    while (n-- > 0) {
        size_t a;
        std::cin >> a;

        if (a > b)
            continue;

        t += a;
        if (t > d) {
            t = 0;
            ++c;
        }
    }

    answer(c);

    return 0;
}

