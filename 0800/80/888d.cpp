#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned k)
{
    integer s = 1;

    if (k > 1)
        s += 1ull * n * (n - 1) / 2;

    if (k > 2)
        s += 2ull * n * (n - 1) * (n - 2) / 6;

    if (k > 3)
        s += 9ull * n * (n - 1) * (n - 2) * (n - 3) / 24;

    answer(s);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}
