#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t m, size_t n)
{
    answer(m * n / 2);
}

int main()
{
    size_t m, n;
    std::cin >> m >> n;

    solve(m, n);

    return 0;
}

