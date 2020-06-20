#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t open_left = 0;
    size_t open_right = 0;
    for (size_t i = 0; i < n; ++i) {
        unsigned left, right;
        std::cin >> left >> right;

        open_left += left;
        open_right += right;
    }

    answer(std::min(open_left, n - open_left) + std::min(open_right, n - open_right));

    return 0;
}

