#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(unsigned k, unsigned l, unsigned m, unsigned n, unsigned d)
{
    size_t count = 0;
    for (unsigned i = 1; i <= d; ++i) {
        if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
            ++count;
    }

    answer(count);
}

int main()
{
    unsigned k, l, m, n, d;
    std::cin >> k >> l >> m >> n >> d;

    solve(k, l, m, n, d);

    return 0;
}

