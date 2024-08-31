#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b)
{
    answer(a ^ b);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);

    return 0;
}
