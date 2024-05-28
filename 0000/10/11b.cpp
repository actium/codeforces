#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned x)
{
    unsigned k = 0;
    for (unsigned d = 0; d < x || (d - x) % 2 != 0; d += k)
        ++k;

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    int x;
    std::cin >> x;

    solve(abs(x));

    return 0;
}
