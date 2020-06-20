#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t w, size_t h, size_t k)
{
    size_t count = 0;
    for (size_t i = 0; i < k; ++i) {
        count += 2 * (h + w - 2);
        h -= 4, w -= 4;
    }

    answer(count);
}

int main()
{
    size_t w, h, k;
    std::cin >> w >> h >> k;

    solve(w, h, k);

    return 0;
}

