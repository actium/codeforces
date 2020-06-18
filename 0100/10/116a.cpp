#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t min_capacity = 0;
    for (size_t i = 0, s = 0; i < n; ++i) {
        size_t a, b;
        std::cin >> a >> b;

        s -= a;
        s += b;

        min_capacity = std::max(min_capacity, s);
    }

    answer(min_capacity);

    return 0;
}

