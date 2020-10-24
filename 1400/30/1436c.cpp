#include <iostream>

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(unsigned n, unsigned x, unsigned p)
{
    constexpr unsigned M = 1000000007;

    unsigned long long k = 1;

    unsigned l = x-1, g = n-x;
    for (unsigned i = 0, j = n; i < j; ) {
        const unsigned m = (i + j) / 2;
        if (m == p) {
            i = m + 1;
        }
        if (m < p) {
            k = k * l-- % M;
            i = m + 1;
        }
        if (m > p) {
            k = k * g-- % M;
            j = m;
        }
    }

    for (unsigned i = 2; i <= l + g; ++i)
        k = (k * i) % M;

    answer(k);
}

int main()
{
    unsigned n, x, p;
    std::cin >> n >> x >> p;

    solve(n, x, p);

    return 0;
}

