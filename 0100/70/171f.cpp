#include <iostream>
#include <vector>

#include <cassert>

void answer(unsigned x)
{
    std::cout << x << '\n';
}

struct Sieve {
    const unsigned upper_bound;

    std::vector<unsigned> smallest_prime_factors;
    std::vector<unsigned> primes;

    explicit Sieve(unsigned upper_bound)
        : upper_bound(upper_bound)
        , smallest_prime_factors(1 + upper_bound)
    {
        for (unsigned i = 2; i <= upper_bound; ++i) {
            if (smallest_prime_factors[i] == 0) {
                smallest_prime_factors[i] = i;
                primes.push_back(i);
            }

            for (const unsigned p : primes) {
                if (p > smallest_prime_factors[i] || i * p > upper_bound)
                    break;

                smallest_prime_factors[i * p] = p;
            }
        }
    }

    bool test_primality(unsigned n) const
    {
        assert(n <= upper_bound && "number is too big");

        return smallest_prime_factors[n] == n;
    }
};

void solve(unsigned n)
{
    const Sieve s(1000000);

    unsigned v = 0;
    for (const unsigned p : s.primes) {
        unsigned r = 0;
        for (unsigned x = p; x != 0; x /= 10)
            r = r * 10 + x % 10;

        if (r != p && s.test_primality(r) && --n == 0) {
            v = p;
            break;
        }
    }

    answer(v);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    solve(n);

    return 0;
}
