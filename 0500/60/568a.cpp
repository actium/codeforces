#include <iostream>
#include <vector>

constexpr unsigned N = 1180000;

void solve(unsigned p, unsigned q)
{
    std::vector<unsigned> d(1+N, 1);
    for (unsigned i = 2; i * i <= N; ++i) {
        if (d[i] == 0)
            continue;

        for (unsigned j = i * i; j <= N; j += i)
            d[j] = 0;
    }

    unsigned n = 1;
    for (unsigned i = 3, k = 2; i <= N; ++i) {
        d[i] += d[i-1];

        unsigned r = 0;
        for (unsigned x = i; x != 0; x /= 10)
            r = r * 10 + x % 10;

        if (r == i)
            ++k;

        if (q * d[i] <= p * k)
            n = i;
    }

    std::cout << n << '\n';
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned p, q;
    std::cin >> p >> q;

    solve(p, q);

    return 0;
}
