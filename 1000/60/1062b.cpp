#include <iostream>
#include <vector>

std::vector<std::pair<unsigned, unsigned>> factorize(unsigned n)
{
    std::vector<std::pair<unsigned, unsigned>> factors;
    for (unsigned i = 2; i * i <= n; ++i) {
        if (n % i != 0)
            continue;

        factors.emplace_back(i, 0);
        while (n % i == 0) {
            ++factors.back().second;
            n /= i;
        }
    }
    if (n != 1)
        factors.emplace_back(n, 1);

    return factors;
}

void answer(unsigned x, unsigned y)
{
    std::cout << x << ' ' << y << '\n';
}

void solve(unsigned n)
{
    const std::vector<std::pair<unsigned, unsigned>> factors = factorize(n);

    unsigned b = 1, p = ~0u, q = 0;
    for (const std::pair<unsigned, unsigned>& f : factors) {
        b *= f.first;
        p = std::min(p, f.second);
        q = std::max(q, f.second);
    }

    unsigned k = (p != q);
    if (__builtin_popcount(q) != 1) {
        q <<= 1;
        k = 1;
    }
    k += __builtin_clz(1) - __builtin_clz(q);

    answer(b, k);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
