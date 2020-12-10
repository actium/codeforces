#include <iostream>

using integer = unsigned long long;

void answer(integer v)
{
    std::cout << v << '\n';
}

void solve(integer n, unsigned x, unsigned y)
{
    const integer d = (x + y) % 2 == 0 ? 0 : (n * n + 1) / 2;

    --x, ++y;

    answer(d + (x * n + y) / 2);
}

int main()
{
    integer n;
    std::cin >> n;

    unsigned q;
    std::cin >> q;

    while (q-- > 0) {
        unsigned x, y;
        std::cin >> x >> y;

        solve(n, x, y);
    }

    return 0;
}

