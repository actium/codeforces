#include <iostream>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unsigned x;
    std::cin >> x;

    unsigned g[3] = { 1, 2, 3 };
    for (size_t i = 0; i < 3; ++i) {
        unsigned a, b;
        std::cin >> a >> b;

        std::swap(g[a-1], g[b-1]);
    }

    for (size_t i = 0; i < 3; ++i) {
        if (g[i] == x)
            std::cout << 1+i << '\n';
    }

    return 0;
}

