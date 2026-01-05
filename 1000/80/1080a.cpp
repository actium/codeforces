#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n, size_t k)
{
    const size_t r = n * 2;
    const size_t g = n * 5;
    const size_t b = n * 8;

    answer((r + k - 1) / k + (g + k - 1) / k + (b + k - 1) / k);
}

int main()
{
    size_t n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

