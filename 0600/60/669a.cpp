#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(size_t n)
{
    answer((2 * n + 1) / 3);
}

int main()
{
    size_t n;
    std::cin >> n;

    solve(n);

    return 0;
}

