#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(unsigned h, integer n)
{
    integer k = 0;
    for (unsigned x = 1; h != 0; --h) {
        const unsigned b = (n >> h - 1) & 0x1;
        k += (b == x ? 1ull << h : 1);
        x = b;
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned h;
    std::cin >> h;

    integer n;
    std::cin >> n;

    solve(h, n-1);

    return 0;
}
