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

unsigned C(unsigned n, unsigned r)
{
    constexpr unsigned MOD = 1000000007;

    static unsigned dp[1001][1001];

    if (r == 0 || r == n)
        return 1;

    if (dp[n][r] == 0)
        dp[n][r] = (C(n-1, r-1) + C(n-1, r)) % MOD;

    return dp[n][r];
}

void answer(unsigned v)
{
    std::cout << v << '\n';
}

void solve(std::vector<unsigned>& a, size_t k)
{
    std::sort(a.begin(), a.end(), std::greater<unsigned>());

    const unsigned n = std::count(a.cbegin(), a.cend(), a[k-1]);
    const unsigned r = std::count(a.cbegin() + k, a.cend(), a[k-1]);

    answer(C(n, r));
}

void test_case()
{
    size_t n, k;
    std::cin >> n >> k;

    std::vector<unsigned> a(n);
    std::cin >> a;

    solve(a, k);
}

int main()
{
    size_t t;
    std::cin >> t;

    while (t-- > 0)
        test_case();

    return 0;
}

