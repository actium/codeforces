#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t w1, size_t h1, size_t w2, size_t h2)
{
    answer(h1 + 1 + h2 + 1 + w1 + 1 + h1 + w2 + 1 + h2 + (w1 - w2));
}

int main()
{
    size_t w1, h1, w2, h2;
    std::cin >> w1 >> h1 >> w2 >> h2;

    solve(w1, h1, w2, h2);

    return 0;
}

