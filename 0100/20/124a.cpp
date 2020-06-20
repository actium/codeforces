#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned a, unsigned b)
{
    answer(std::min(n - a, b + 1));
}

int main()
{
    unsigned n, a, b;
    std::cin >> n >> a >> b;

    solve(n, a, b);

    return 0;
}

