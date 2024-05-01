#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a)
{
    answer(1 + (a - 1) % 9);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned a;
    std::cin >> a;

    solve(a);

    return 0;
}
