#include <iostream>

using integer = unsigned long long;

void answer(integer x)
{
    std::cout << x << '\n';
}

void solve(integer n, integer l, integer r)
{
    if (n == 0)
        return answer(0);

    const unsigned w = __builtin_clzll(1) - __builtin_clzll(n) + 1;

    const auto count = [=](integer x, unsigned b) {
        const integer d = 1ull << w - b - 1;
        return (x + d) / (2 * d);
    };

    integer k = 0;
    for (unsigned i = 0; i < w; ++i) {
        if ((n & 1ull << i) != 0)
            k += count(r, i) - count(l-1, i);
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    integer n, l, r;
    std::cin >> n >> l >> r;

    solve(n, l, r);

    return 0;
}
