#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned x)
{
    unsigned k = 0;
    for (unsigned i = 1; i <= n; ++i) {
        if (x % i == 0 && x / i <= n)
            ++k;
    }

    answer(k);
}

int main()
{
    unsigned n, x;
    std::cin >> n >> x;

    solve(n, x);

    return 0;
}

