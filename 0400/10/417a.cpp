#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned c, unsigned d, unsigned n, unsigned m, unsigned k)
{
    unsigned q = ~0u;
    for (unsigned u = 0; u <= m; ++u) {
        unsigned v = 0;
        while (u * n + v + k < n * m)
            ++v;

        q = std::min(q, u * c + v * d);
    }

    answer(q);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned c, d, n, m, k;
    std::cin >> c >> d >> n >> m >> k;

    solve(c, d, n, m, k);

    return 0;
}
