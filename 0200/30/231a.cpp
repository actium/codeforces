#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t count = 0;
    for (size_t i = 0; i < n; ++i) {
        unsigned m1, m2, m3;
        std::cin >> m1 >> m2 >> m3;

        if (m1 + m2 + m3 > 1)
            ++count;
    }

    answer(count);

    return 0;
}

