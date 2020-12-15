#include <algorithm>
#include <iostream>
#include <vector>

constexpr unsigned MOD = 1000000007;

template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& v)
{
    for (T& a : v)
        input >> a;

    return input;
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

using integer = unsigned long long;

unsigned factorial(unsigned n)
{
    constexpr size_t N = 200000;

    static unsigned dp[1+N] = { 1 };

    if (dp[n] == 0)
        dp[n] = 1ull * n * factorial(n-1) % MOD;

    return dp[n];
}

unsigned raise(integer base, unsigned power)
{
    unsigned value = 1;
    while (power > 0) {
        if (power & 1)
            value = (value * base) % MOD;

        base = (base * base) % MOD;
        power >>= 1;
    }
    return value;
}

unsigned C(unsigned n, unsigned r)
{
    if (n < r)
        return 0;

    return 1ull * factorial(n) * raise(factorial(r), MOD-2) % MOD * raise(factorial(n-r), MOD-2) % MOD;
}

void solve(std::vector<unsigned>& a, unsigned m, unsigned k)
{
    const size_t n = a.size();

    std::sort(a.begin(), a.end());

    unsigned c = 0;
    for (size_t i = 0, j = 0; i + m - 1 < n; ++i) {
        while (j - i < m - 1)
            ++j;

        while (j < n && a[j] - a[i] <= k)
            ++j;

        c = (c + C(j-i-1, m-1)) % MOD;
    }

    answer(c);
}

void test_case()
{
    size_t n;
    std::cin >> n;

    unsigned m, k;
    std::cin >> m >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, m, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

