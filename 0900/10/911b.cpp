#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned a, unsigned b)
{
    unsigned x = 0;
    for (unsigned i = 1; i < n; ++i) {
        if (a < i || b < n - i)
            continue;

        const unsigned k = std::min(a / i, b / (n-i));
        x = std::max(x, k);
    }

    answer(x);
}

int main()
{
    unsigned n, a, b;
    std::cin >> n >> a >> b;

    solve(n, a, b);

    return 0;
}

