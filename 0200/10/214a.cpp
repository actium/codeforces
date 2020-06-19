#include <iostream>

void answer(size_t v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned m)
{
    size_t count = 0;
    for (unsigned a = 0; a * a <= n; ++a) {
        const unsigned b = n - a * a;
        if (a + b * b == m)
            ++count;
    }

    answer(count);
}

int main()
{
    unsigned n, m;
    std::cin >> n >> m;

    solve(n, m);

    return 0;
}

