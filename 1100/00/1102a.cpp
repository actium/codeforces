#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(unsigned n)
{
    answer(1 ^ ((n - 1) % 4) / 2);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}

