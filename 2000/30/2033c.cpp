#include <array>
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

void solve(const std::vector<unsigned>& a)
{
    const size_t n = a.size();

    std::array<unsigned, 4> dp = {};
    for (size_t i = 1, j = n-2; i <= j; ++i, --j) {
        const unsigned pp = a[i-1], p = a[i], s = a[j], ss = a[j+1];
        dp = {
            std::min(dp[0], dp[2]) + (pp == p) + (s == ss),
            std::min(dp[0], dp[2]) + (pp == s) + (p == ss),
            std::min(dp[1], dp[3]) + (ss == p) + (s == pp),
            std::min(dp[1], dp[3]) + (ss == s) + (p == pp),
        };
    }

    unsigned k = ~0u;
    for (size_t i = 0; i < 4; ++i)
        k = std::min(k, dp[i]);

    if (n % 2 == 0 && a[n/2] == a[n/2-1])
        ++k;

    answer(k);
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
