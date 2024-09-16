#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    answer(n == 3 ? 24 : (12ull << 2 * n - 8) * (3 * n - 1));
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
