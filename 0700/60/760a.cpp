#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t m, size_t d)
{
    constexpr size_t s[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    const size_t k = s[m-1];
    answer(1 + (k - (8 - d) + 6) / 7);
}

int main()
{
    unsigned m, d;
    std::cin >> m >> d;

    solve(m, d);

    return 0;
}

