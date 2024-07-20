#include <iostream>
#include <vector>

constexpr unsigned N = 5000000;

unsigned c[1+N];

void initialize()
{
    std::vector<unsigned> spf(1+N), primes;
    for (unsigned i = 2; i <= N; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }

        for (const unsigned p : primes) {
            if (p > spf[i] || i * p > N)
                break;

            spf[i*p] = p;
        }

        c[i] = c[i-1];
        for (unsigned x = i; x != 1; x /= spf[x])
            ++c[i];
    }
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned a, unsigned b)
{
    answer(c[a] - c[b]);
}

void test_case()
{
    unsigned a, b;
    std::cin >> a >> b;

    solve(a, b);
}

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);

    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
