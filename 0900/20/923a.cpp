#include <iostream>
#include <vector>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

struct Sieve {
    const unsigned upper_bound;

    std::vector<unsigned> spf;
    std::vector<unsigned> primes;

    explicit Sieve(unsigned upper_bound)
        : upper_bound(upper_bound)
        , spf(1 + upper_bound)
    {
        for (unsigned i = 2; i <= upper_bound; ++i) {
            if (spf[i] == 0) {
                spf[i] = i;
                primes.push_back(i);
            }

            for (const unsigned p : primes) {
                if (p > spf[i] || i * p > upper_bound)
                    break;

                spf[i * p] = p;
            }
        }
    }

    unsigned max_prime_factor(unsigned n) const
    {
        unsigned x = 1;
        while (n > 1) {
            x = spf[n];
            do {
                n /= x;
            } while (spf[n] == x);
        }
        return x;
    }
};

void solve(unsigned n)
{
    const Sieve sieve(n);

    unsigned x = n;
    for (unsigned i = n - sieve.max_prime_factor(n) + 1; i <= n; ++i) {
        const unsigned y = i - sieve.max_prime_factor(i) + 1;
        if (y >= 3 && y <= i)
            x = std::min(x, y);
    }

    answer(x);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
