#include <iostream>
#include <vector>

constexpr unsigned K = 10'000'000;

unsigned t[1+K];

void initialize()
{
    std::vector<unsigned> spf(1+K), primes;
    for (unsigned i = 2; i <= K; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }

        for (const unsigned p : primes) {
            if (p > spf[i] || i * p > K)
                break;

            spf[i*p] = p;
        }
    }

    std::vector<unsigned long long> sigma(1+K, 1);
    for (unsigned i = 2; i <= K; ++i) {
        unsigned j = i;
        while (j % spf[i] == 0) {
            sigma[i] = sigma[i] * spf[i] + 1;
            j /= spf[i];
        }
        sigma[i] *= sigma[j];
    }

    for (unsigned i = 1; i <= K; ++i) {
        if (sigma[i] <= K && t[sigma[i]] == 0)
            t[sigma[i]] = i;
    }
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void no_answer()
{
    std::cout << -1 << '\n';
}

void solve(unsigned c)
{
    if (t[c] != 0)
        answer(t[c]);
    else
        no_answer();
}

void test_case()
{
    unsigned c;
    std::cin >> c;

    solve(c);
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