#include <iostream>
#include <utility>

void answer(double v)
{
    std::cout << std::fixed << v << '\n';
}

int main()
{
    size_t n, m;
    std::cin >> n >> m;

    std::pair<size_t, size_t> min_cost = { 1, 0 };
    for (size_t i = 0; i < n; ++i) {
        size_t a, b;
        std::cin >> a >> b;

        if (a * min_cost.second < min_cost.first * b) {
            min_cost.first = a;
            min_cost.second = b;
        }
    }

    answer(1.0 * m * min_cost.first / min_cost.second);

    return 0;
}

