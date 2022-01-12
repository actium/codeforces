#include <iostream>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n, unsigned k)
{
    constexpr unsigned M = 1000000007;

    std::vector<std::vector<unsigned>> x(1+n);
    for (unsigned i = 1; i <= n; ++i) {
        for (unsigned j = i; j <= n; j += i)
            x[i].push_back(j);
    }

    std::vector<unsigned> c(1+n, 1);
    while (--k > 0) {
        std::vector<unsigned> d(1+n);
        for (unsigned i = 1; i <= n; ++i) {
            for (const unsigned j : x[i])
                d[j] = (d[j] + c[i]) % M;
        }
        c = std::move(d);
    }

    unsigned s = 0;
    for (unsigned i = 1; i <= n; ++i)
        s = (s + c[i]) % M;

    answer(s);
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}
