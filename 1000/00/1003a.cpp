#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    size_t f[101] = {}, c = 0;
    for (size_t i = 0; i < n; ++i) {
        unsigned a;
        std::cin >> a;

        c = std::max(c, ++f[a]);
    }

    answer(c);

    return 0;
}

