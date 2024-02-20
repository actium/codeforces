#include <iostream>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

unsigned count(unsigned n, unsigned a, unsigned b)
{
    unsigned k = 0;
    for (unsigned i = 0; i <= b && i <= n; ++i) {
        if ((n - i) * 2 <= a)
            ++k;
    }
    return k;
}

void solve(unsigned n, unsigned a, unsigned b, unsigned c)
{
    unsigned k = 0;
    for (unsigned i = 0; i <= c && i * 2 <= n; ++i)
        k += count(n - i * 2, a, b);

    answer(k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n, a, b, c;
    std::cin >> n >> a >> b >> c;

    solve(n, a, b, c);

    return 0;
}
