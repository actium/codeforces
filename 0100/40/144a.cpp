#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    std::pair<size_t, unsigned> min = { n, 0 }, max = { n, 0 };
    for (size_t i = 0; i < n; ++i) {
        unsigned height;
        std::cin >> height;

        if (max.first == n || height > max.second)
            max = { i, height };

        if (min.first == n || height <= min.second)
            min = { i, height };
    }

    answer(max.first + (n - 1 - min.first) - (max.first > min.first));

    return 0;
}

