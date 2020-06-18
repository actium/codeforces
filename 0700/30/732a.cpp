#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t k, size_t r)
{
    size_t n = 1;
    while (n * k % 10 != 0 && n * k % 10 != r)
        ++n;

    answer(n);
}

int main()
{
    size_t k, r;
    std::cin >> k >> r;

    solve(k, r);

    return 0;
}

