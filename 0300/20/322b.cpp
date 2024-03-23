#include <algorithm>
#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned r, unsigned g, unsigned b)
{
    const unsigned ub = std::min({ r, g, b, 3u });

    unsigned k = r / 3 + g / 3 + b / 3;
    for (unsigned i = 0; i < ub; ++i) {
        const unsigned d = std::min({ r, g, b }) - i;
        k = std::max(k, d + (r - d) / 3 + (g - d) / 3 + (b - d) / 3);
    }

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned r, g, b;
    std::cin >> r >> g >> b;

    solve(r, g, b);

    return 0;
}
