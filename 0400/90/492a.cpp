#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n)
{
    size_t h = 0;
    for (size_t d = 1; d <= n; n -= d, d += h + 1)
        ++h;

    answer(h);
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}

