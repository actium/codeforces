#include <algorithm>
#include <iostream>
#include <vector>

void answer(const std::vector<unsigned>& v)
{
    const char* separator = "";
    for (const unsigned x : v) {
        std::cout << separator << x;
        separator = " ";
    }
    std::cout << '\n';
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
};

void solve(unsigned n)
{
    const Sieve sieve(n);

    std::vector<std::vector<unsigned>> g(1+n);
    for (unsigned i = 2; i <= n; ++i) {
        unsigned x = i;
        while (sieve.smallest_prime_factors[x] != x)
            x /= sieve.smallest_prime_factors[x];

        g[x].push_back(i);
    }

    std::vector<unsigned> p(n);
    p[0] = 1;
    for (const unsigned x : sieve.primes) {
        for (size_t i = 0, k = g[x].size(); i < k; ++i) {
            const unsigned u = g[x][i], v = g[x][(i+1)%k];
            p[u-1] = v;
        }
    }

    answer(p);
}

void test_case()
{
    unsigned n;
    std::cin >> n;

    solve(n);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
