#include <iostream>
#include <vector>

template <typename T, typename U>
std::istream& operator >>(std::istream& input, std::pair<T, U>& v)
{
    return input >> v.first >> v.second;
}

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void status(const char* x)
{
    std::cout << x << '\n';
}

void conflict(unsigned x)
{
    std::cout << "Conflict with " << x << '\n';
}

struct Sieve {
    const unsigned upper_bound;

    std::vector<unsigned> smallest_prime_factors;

    explicit Sieve(unsigned upper_bound)
        : upper_bound(upper_bound)
        , smallest_prime_factors(1 + upper_bound)
    {
        std::vector<unsigned> primes;
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

    std::vector<unsigned> factorize_number(unsigned n) const
    {
        if (n == 1)
            return { 1 };

        std::vector<unsigned> factors;
        while (n > 1) {
            factors.push_back(smallest_prime_factors[n]);

            while (smallest_prime_factors[n] == factors.back())
                n /= factors.back();
        }
        return factors;
    }
};

void solve(unsigned n, const std::vector<std::pair<char, unsigned>>& r)
{
    const Sieve s(n);

    std::vector<unsigned> x(1 + n);

    const auto toggle = [&](unsigned u, const std::vector<unsigned>& factors) {
        unsigned c = 0;
        for (const unsigned p : factors) {
            c = std::max(c, x[p]);
            x[p] ^= u;
        }
        return c;
    };

    for (const std::pair<char, unsigned>& q : r) {
        const std::vector<unsigned> factors = s.factorize_number(q.second);

        const unsigned c = toggle(q.second, factors);
        if (q.first == '+' && c == q.second) {
            status("Already on");
            toggle(q.second, factors);
            continue;
        }
        if (q.first == '+' && c != 0) {
            conflict(c);
            toggle(q.second, factors);
            continue;
        }
        if (q.first == '-' && c != q.second) {
            toggle(q.second, factors);
            status("Already off");
            continue;
        }
        status("Success");
    }
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    unsigned n;
    std::cin >> n;

    size_t m;
    std::cin >> m;

    std::vector<std::pair<char, unsigned>> r(m);
    std::cin >> r;

    solve(n, r);

    return 0;
}
