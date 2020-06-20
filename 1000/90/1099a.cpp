#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(int w, size_t h, int u1, size_t d1, int u2, size_t d2)
{
    while (h > 0) {
        w += h;

        if (h == d1)
            w = std::max(0, w - u1);

        if (h == d2)
            w = std::max(0, w - u2);

        --h;
    }

    answer(w);
}

int main()
{
    size_t w, h;
    std::cin >> w >> h;

    size_t u1, d1;
    std::cin >> u1 >> d1;

    size_t u2, d2;
    std::cin >> u2 >> d2;

    solve(w, h, u1, d1, u2, d2);

    return 0;
}

