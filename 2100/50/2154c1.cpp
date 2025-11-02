#include <iostream>
#include <map>
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

    std::vector<unsigned> factorize(unsigned x) const
    {
        std::vector<unsigned> factors;
        while (x != 1) {
            if (factors.empty() || smallest_prime_factors[x] != factors.back())
                factors.push_back(smallest_prime_factors[x]);

            x /= smallest_prime_factors[x];
        }
        return factors;
    }
};

const Sieve soe(200001);

void solve(std::vector<unsigned>& a, const std::vector<unsigned>& b)
{
    std::map<unsigned, unsigned> c;
    for (const unsigned x : a) {
        for (const unsigned p : soe.factorize(x))
            ++c[p];
    }

    for (const auto& e : c) {
        if (e.second >= 2)
            return answer(0);
    }

    std::map<unsigned, unsigned> d;
    for (const unsigned x : a) {
        for (const unsigned p : soe.factorize(x+1))
            ++d[p];
    }

    for (const auto& e : d) {
        if (c.find(e.first) != c.end())
            return answer(1);
    }

    answer(2);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    std::vector<unsigned> a(n), b(n);
    std::cin >> a >> b;

    solve(a, b);
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
