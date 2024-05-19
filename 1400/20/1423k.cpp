#include <iostream>
#include <vector>

#include <cmath>

constexpr unsigned N = 1000000;

std::vector<unsigned> primes;
std::vector<unsigned> pi(1 + N);

void initialize()
{
    std::vector<unsigned> lp(1 + N);
    for (unsigned i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back(i);
            pi[i] = 1;
        }

        for (unsigned j = 0; i * primes[j] <= N; ++j) {
            lp[i * primes[j]] = primes[j];
            if (primes[j] == lp[i])
                break;
        }
    }

    for (unsigned i = 3; i <= N; ++i)
        pi[i] += pi[i-1];
}

void answer(unsigned x)
{
    std::cout << x << '\n';
}

void solve(unsigned n)
{
    answer(pi[n] - pi[sqrt(n)] + 1);
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

    initialize();

    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}
