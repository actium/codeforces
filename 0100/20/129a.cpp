#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

int main()
{
    size_t n;
    std::cin >> n;

    unsigned f[2] = {};
    for (size_t i = 0; i < n; ++i) {
        unsigned a;
        std::cin >> a;

        ++f[a % 2];
    }

    answer(f[f[1] % 2]);

    return 0;
}

