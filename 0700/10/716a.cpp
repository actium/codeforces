#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n, c;
    std::cin >> n >> c;

    size_t count = 0, last_t;
    for (size_t i = 0; i < n; ++i) {
        size_t t;
        std::cin >> t;

        if (i > 0 && last_t + c < t)
            count = 0;

        last_t = t;
        ++count;
    }

    answer(count);

    return 0;
}

