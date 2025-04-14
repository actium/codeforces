#include <iostream>
#include <vector>

std::vector<unsigned> primes;

void prepare()
{
    constexpr unsigned K = 10000000;

    std::vector<unsigned> spf(1+K);
    for (unsigned i = 2; i <= K; ++i) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }

        for (const unsigned p : primes) {
            if (p > spf[i] || i * p > K)
                break;

            spf[i * p] = p;
        }
    }
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    unsigned k = 0;
    for (const int p : primes) {
        if (p > n)
            break;

        k += n / p;
    }

    answer(k);
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

    prepare();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
