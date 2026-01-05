#include <bitset>
#include <iostream>

#include <cmath>

std::bitset<1000000> sieve;

void fill_sieve()
{
    sieve.set(0);

    for (size_t prime = 2; prime * prime <= 1000000; ) {
        for (size_t i = prime * prime; i <= 1000000; i += prime)
            sieve.set(i - 1);

        while (++prime < 1000000 && sieve.test(prime - 1));
    }
}

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(uint64_t x)
{
    const uint64_t sr = sqrt(x);

    answer(sr * sr == x && !sieve.test(sr - 1));
}

int main()
{
    size_t n;
    std::cin >> n;

    fill_sieve();

    while (n-- > 0) {
        uint64_t x;
        std::cin >> x;

        solve(x);
    }

    return 0;
}

