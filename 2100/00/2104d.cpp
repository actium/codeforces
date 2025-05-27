#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

struct Sieve {
    std::vector<unsigned> primes;

    explicit Sieve(unsigned upper_bound)
    {
        std::vector<unsigned> spf(1 + upper_bound);
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
};

Sieve sieve(5800085);

void solve(std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end(), std::greater<unsigned>());

    unsigned k = 0;
    for (unsigned long long c = 0, d = 0; k < n && c + a[k] >= d + sieve.primes[k]; ++k) {
        c += a[k];
        d += sieve.primes[k];
    }

    answer(n - k);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a);
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
