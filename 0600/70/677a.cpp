#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n, h;
    std::cin >> n >> h;

    size_t c = 0;
    for (size_t i = 0; i < n; ++i) {
        size_t a;
        std::cin >> a;

        if (a > h)
            ++c;
    }

    answer(n + c);

    return 0;
}

