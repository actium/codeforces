#include <iostream>
#include <vector>

constexpr unsigned M = 1000000007;

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    std::vector<unsigned> a(1+n), b(1+n), c(1+n), d(1+n);
    d[0] = 1;
    for (unsigned i = 1; i <= n; ++i) {
        a[i] = (b[i-1] + c[i-1] + d[i-1]) % M;
        b[i] = (a[i-1] + c[i-1] + d[i-1]) % M;
        c[i] = (a[i-1] + b[i-1] + d[i-1]) % M;
        d[i] = (a[i-1] + b[i-1] + c[i-1]) % M;
    }

    answer(d[n]);
}

int main()
{
    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
