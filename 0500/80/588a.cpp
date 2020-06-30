#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t s = 0;
    for (size_t i = 0, r = 100; i < n; ++i) {
        size_t a, p;
        std::cin >> a >> p;

        r = std::min(r, p);
        s += a * r;
    }

    answer(s);

    return 0;
}

