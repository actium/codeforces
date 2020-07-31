#include <algorithm>
#include <iostream>
#include <vector>

void answer(bool v)
{
    constexpr const char* s[2] = { "NO", "YES" };
    std::cout << s[v] << '\n';
}

void solve(unsigned n, unsigned k)
{
    std::vector<unsigned> primes = { 2 };
    for (unsigned x = 3; x <= n; x += 2) {
        if (std::any_of(primes.cbegin(), primes.cend(), [x](unsigned p) { return x % p == 0; }))
            continue;

        primes.push_back(x);
    }

    unsigned c = 0;
    for (size_t i = 1; i < primes.size(); ++i) {
        if (std::find(primes.cbegin(), primes.cend(), primes[i-1] + primes[i] + 1) != primes.cend())
            ++c;
    }

    answer(c >= k);
}

int main()
{
    unsigned n, k;
    std::cin >> n >> k;

    solve(n, k);

    return 0;
}

