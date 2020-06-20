#include <iostream>

void answer(uint64_t v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    uint64_t t = 0;

    unsigned x = 1;
    for (size_t i = 0; i < m; ++i) {
        unsigned a;
        std::cin >> a;

        if (a >= x)
            t += a - x;
        else
            t += n - (x - a);

        x = a;
    }

    answer(t);

    return 0;
}

